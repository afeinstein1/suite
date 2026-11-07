$ErrorActionPreference = "Stop"

Set-Location $PSScriptRoot

Write-Host "Configuring project..." -ForegroundColor Cyan

cmake -S . -B build -G Ninja

if ($LASTEXITCODE -ne 0) {
    throw "CMake configuration failed."
}

Write-Host "Building project..." -ForegroundColor Cyan

cmake --build build

if ($LASTEXITCODE -ne 0) {
    throw "Build failed."
}

Write-Host "Build completed successfully!" -ForegroundColor Green