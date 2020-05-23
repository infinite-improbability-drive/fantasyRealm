#!/bin/bash

Write-Host "Hello, World!"
Start-Sleep -Seconds 5
$CharBytes = 169, 244, 1, 0
[System.Text.Encoding]::UTF32.GetString($CharBytes)