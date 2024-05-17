#!/bin/bash
cd project-report
./../exe/run_project
gprof ../exe/run_project gmon.out > analysis.txt
