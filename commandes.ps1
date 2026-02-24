function Executer-Exemple {
    [CmdletBinding()]
    Param(
        [Parameter(Mandatory = $true)] [string] $Projet,
        [Parameter(Mandatory = $false)] [string] $Fonction
    )

    # Utiliser main.c par défaut si Fonction n'est pas spécifiée
    if ([string]::IsNullOrEmpty($Fonction)) {
        $fichierSource = Join-Path "exemples/$Projet" "main.c"
    }
    else {
        $fichierSource = Join-Path "exemples/$Projet" "exemple_$Fonction.c"
    }

    $repertoireSortie = Join-Path "bin" $Projet
    New-Item -ItemType Directory -Force -Path $repertoireSortie | Out-Null
    $nomFichier = [System.IO.Path]::GetFileNameWithoutExtension((Split-Path $fichierSource -Leaf))
    $executable = Join-Path $repertoireSortie "$nomFichier.exe"

    if (-not (Test-Path $fichierSource)) {
        Write-Host "Fichier source introuvable : $fichierSource" -ForegroundColor Red
        return 2
    }

    $fichiersSrc = Get-ChildItem -Path src -Filter *.c -File | ForEach-Object { $_.FullName }

    $gcc = "gcc"
    $argumentsGcc = @("-std=c11", "-Wall", "-Wextra", "-Iinclude", $fichierSource) + $fichiersSrc + @("-o", $executable)

    & $gcc @argumentsGcc 2>&1
    $codeRetour = $LASTEXITCODE

    if ($codeRetour -eq 0) {
        & $executable 2>&1
        $codeRetour = $LASTEXITCODE

        if ($codeRetour -eq 0) {
            Write-Host "Code de sortie: 0" -ForegroundColor Green
        }
        else {
            Write-Host "Code de sortie : $codeRetour" -ForegroundColor Red
        }
    }
}