<#
.SYNOPSIS
    Compile et exécute l'exemple d'un projet.

.DESCRIPTION
    La fonction Executer-Exemple permet de compiler et d'exécuter l'exemple d'un projet
    en compilant d'abord main.c puis tous les autres fichiers .c situés dans le répertoire
    exemples/<projet>. Elle utilise gcc pour la compilation et génère l'exécutable dans
    le répertoire bin/<projet>/<projet>.exe.

.PARAMETER Projet
    Nom du projet/dossier dans le répertoire exemples. Ce paramètre est obligatoire.

.EXAMPLE
   Executer-Exemple -Projet "liste"
   Compile main.c et exemple.c de exemples/liste/, plus src/*.c, génère bin/liste/liste.exe et l'exécute.

.NOTES
    Les fichiers sources doivent se trouver dans le répertoire src/ pour être inclus
    lors de la compilation. Le répertoire exemples/<projet> doit contenir main.c.
#>
function Executer-Exemple {
    [CmdletBinding()]
    Param(
        [Parameter(Mandatory = $true)] [string] $Projet
    )

    $repertoireExemples = Join-Path "exemples" $Projet

    if (-not (Test-Path $repertoireExemples)) {
        Write-Host "Répertoire d'exemples introuvable : $repertoireExemples" -ForegroundColor Red
        return 2
    }

    $mainFile = Join-Path $repertoireExemples "main.c"

    if (-not (Test-Path $mainFile)) {
        Write-Host "Fichier main.c introuvable dans $repertoireExemples" -ForegroundColor Red
        return 2
    }

    $fichiersExemples = Get-ChildItem -Path $repertoireExemples -Filter "*.c" -File |
                        Where-Object { $_.Name -ne "main.c" } |
                        ForEach-Object { $_.FullName }

    $repertoireSortie = Join-Path "bin" $Projet
    New-Item -ItemType Directory -Force -Path $repertoireSortie | Out-Null

    $fichiersSrc = Get-ChildItem -Path src -Filter *.c -File | ForEach-Object { $_.FullName }
    $gcc = "gcc"

    $executable = Join-Path $repertoireSortie ("{0}.exe" -f $Projet)

    Write-Host "Compilation de l'exemple : $Projet" -ForegroundColor Cyan
    $argumentsGcc = @("-std=c11", "-Wall", "-Wextra", "-Iinclude", $mainFile) + $fichiersExemples + $fichiersSrc + @("-o", $executable)

    & $gcc @argumentsGcc 2>&1
    $codeRetour = $LASTEXITCODE

    if ($codeRetour -ne 0) {
        Write-Host "Échec de la compilation pour $Projet (code=$codeRetour)" -ForegroundColor Red
        return $codeRetour
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
}