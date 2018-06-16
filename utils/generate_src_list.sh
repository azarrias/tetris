#!/bin/bash
# Title:        generate_src_list.sh
# Description:  Generates a CMakeLists.txt file that contains the current list of 
#               source files located in the /src folder.
# Author:       azarrias
# Date:         20180611
# Usage:        ./generate_src_list.sh
#================================================================================

V_PROJECT="pong"
V_CMAKELISTS_PATH="../src/CMakeLists.txt"
IFS='
'

SRC_RELATIVE_PATH=`dirname $V_CMAKELISTS_PATH`
SRC_FILES_ARRAY=(`ls -1d $SRC_RELATIVE_PATH/*.{cpp,c,hpp,h,inl,inc} 2>/dev/null`)

echo "target_sources($V_PROJECT PRIVATE" > "$V_CMAKELISTS_PATH"

for i in ${SRC_FILES_ARRAY[*]}; do
   echo "   \${CMAKE_CURRENT_LIST_DIR}/`basename $i`" >> "$V_CMAKELISTS_PATH"
done

echo ")" >> "$V_CMAKELISTS_PATH"