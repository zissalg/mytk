#!/bin/sh

ASSETS_DIR=assets
BUILD_DIR=build
EXE_FILE=RescueGlassiz

cp -rf ${ASSETS_DIR} ${BUILD_DIR}

cd ${BUILD_DIR}

cmake ../
make

echo "-------------------------------------------------------------------"
# Run executable if exist
if [ -e ${EXE_FILE} ]
then
	echo "Run ${EXE_FILE}"
	./${EXE_FILE}
	rm ${EXE_FILE}
fi
