#!/bin/bash
TEMPLATE_PATH=./

for CLASS in "$@"
do
	sed "s/Sample/${CLASS}/g" ${TEMPLATE_PATH}Sample.cpp > ${CLASS}.cpp
	sed "s/Sample/${CLASS}/g" ${TEMPLATE_PATH}Sample.hpp > ${CLASS}.hpp
	sed -i "s/SAMPLE/${CLASS^^}/g" ${CLASS}.hpp
done