#!/bin/bash

CodeChecker analyze compile_commands.json \
    --ignore .CodeChecker/skipfile_bazel.txt \
    -o reports

# MISRA checking via CodeChecker isn't working properly. Use ./.cppcheck/run.sh instead.
# CodeChecker analyze compile_commands.json \
#     --ignore .CodeChecker/skipfile_bazel.txt \
#     --ignore .CodeChecker/skipfile_thirdparty.txt \
#     --cppcheckargs .CodeChecker/cppcheckargs.txt \
#     --analyzer-config cppcheck:addons=.cppcheck/misra.json \
#     --analyzer-config cppcheck:platform=unix64 \
#     -o misra_reports 