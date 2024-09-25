#!/bin/bash
for i in {1..20}; do
    mkdir week-$i
    touch ./week-$i/.gitkeep
    touch ./week-$i/README.md
    mkdir week-$i/classwork
    touch ./week-$i/classwork/.gitkeep
    mkdir week-$i/homework
    touch ./week-$i/homework/.gitkeep
done