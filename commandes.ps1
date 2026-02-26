<#
.SYNOPSIS
    Compile et exécute un fichier exemple du projet.

.DESCRIPTION
    La fonction Executer-Exemple permet de compiler et d'exécuter les fichiers sources
    d'exemples situés dans le répertoire exemples/<projet>. Elle utilise gcc pour la
    compilation et génère l'exécutable dans le répertoire bin/<projet>.

.PARAMETER Projet
    Nom du projet/dossier dans le répertoire exemples. Ce paramètre est obligatoire.

.PARAMETER Fonction
   Nom logique de l'exemple à exécuter (sans le préfixe \"exemple_\").
   - Si non spécifié : exécute tous les fichiers exemple_*.c du projet.
   - Si égal à \"*\"   : exécute tous les fichiers exemple_*.c du projet.
   - Sinon           : exécute exemples/<projet>/exemple_<Fonction>.c

.EXAMPLE
   Executer-Exemple -Projet "liste"
   Exécute tous les fichiers exemples/liste/exemple_*.c
 
.EXAMPLE
   Executer-Exemple -Projet "liste" -Fonction "liste_ajout"
   Exécute le fichier exemples/liste/exemple_liste_ajout.c
 
.EXAMPLE
   Executer-Exemple -Projet "liste" -Fonction "*"
   Exécute tous les fichiers exemples/liste/exemple_*.c

.NOTES
    Les fichiers sources doivent se trouver dans le répertoire src/ pour être inclus
    lors de la compilation. Les exécutables sont générés dans bin/<projet>/.
#>
function Executer-Exemple {
    [CmdletBinding()]
    Param(
        [Parameter(Mandatory = $true)] [string] $Projet,
        [Parameter(Mandatory = $false)] [string] $Fonction
    )

    $repertoireExemples = Join-Path "exemples" $Projet

    if (-not (Test-Path $repertoireExemples)) {
        Write-Host "Répertoire d'exemples introuvable : $repertoireExemples" -ForegroundColor Red
        return 2
    }

    # Récupération des fichiers sources d'exemple à compiler/exécuter
    if ([string]::IsNullOrEmpty($Fonction) -or $Fonction -eq "*") {
        # Tous les fichiers exemple_*.c du projet
        $fichiersExemples = Get-ChildItem -Path $repertoireExemples -Filter "exemple_*.c" -File |
                            Sort-Object Name
        if (-not $fichiersExemples) {
            Write-Host "Aucun fichier exemple_*.c trouvé dans $repertoireExemples" -ForegroundColor Yellow
            return 3
        }
    }
    else {
        # Un seul fichier spécifique : exemples/<projet>/exemple_<Fonction>.c
        $fichierUnique = Join-Path $repertoireExemples ("exemple_{0}.c" -f $Fonction)
        if (-not (Test-Path $fichierUnique)) {
            Write-Host "Fichier source introuvable : $fichierUnique" -ForegroundColor Red
            return 2
        }
        $fichiersExemples = ,(Get-Item $fichierUnique)
    }

    $repertoireSortie = Join-Path "bin" $Projet
    New-Item -ItemType Directory -Force -Path $repertoireSortie | Out-Null

    $fichiersSrc = Get-ChildItem -Path src -Filter *.c -File | ForEach-Object { $_.FullName }
    $gcc = "gcc"

    foreach ($fichierSourceItem in $fichiersExemples) {
        $fichierSource = $fichierSourceItem.FullName
        $nomFichier = [System.IO.Path]::GetFileNameWithoutExtension($fichierSourceItem.Name)
        $executable = Join-Path $repertoireSortie ("{0}.exe" -f $nomFichier)

        Write-Host "Compilation de l'exemple : $($fichierSourceItem.Name)" -ForegroundColor Cyan
        $argumentsGcc = @("-std=c11", "-Wall", "-Wextra", "-Iinclude", $fichierSource) + $fichiersSrc + @("-o", $executable)

        & $gcc @argumentsGcc 2>&1
        $codeRetour = $LASTEXITCODE

        if ($codeRetour -ne 0) {
            Write-Host "Échec de la compilation pour $($fichierSourceItem.Name) (code=$codeRetour)" -ForegroundColor Red
            continue
        }

        Write-Host "Exécution de $($executable)..." -ForegroundColor Green
        & $executable 2>&1
        $codeRetour = $LASTEXITCODE

        if ($codeRetour -eq 0) {
            Write-Host "Code de sortie: 0" -ForegroundColor Green
        }
        else {
            Write-Host "Code de sortie : $codeRetour" -ForegroundColor Red
        }

        Write-Host ("-" * 60)
    }
}