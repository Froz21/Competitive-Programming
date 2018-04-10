#!/bin/bash

for dir in */ ; do
    notebook-generator "$dir" "${dir%?}.pdf"
done
notebook-generator "${0%/*}" "Full Notebook.pdf"
