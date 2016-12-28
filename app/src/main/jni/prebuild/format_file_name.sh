#!/bin/bash

path="/cygdrive/c/Users/shenjinqi/StudioProjects/Mcpttclient/app/src/main/jni/prebuild/pjsip_mcptt"

path_other="/cygdrive/c/Users/shenjinqi/StudioProjects/Mcpttclient/app/src/main/jni/prebuild/other"

# find pjsip_mcptt -follow -name '*.a'|sed -n 's/\(.*lib\w\+\)-.*/mv & \1.a/e'
# find pjsip_mcptt -follow -name '*.a'|sed -n 's/\(.*lib.*\)-.*/\1.a/p'|sed -n 's/\(.*lib.*\)-.*/\1.a/p'|sed -n 's/\(.*lib.*\)-.*/\1.a/p'|sed -n 's/\(.*lib.*\)-.*/\1.a/p'
# repeat 4 times
# find pjsip_mcptt -follow -name '*.a'|sed -n 's/\(.*lib.*\)-.*/mv & \1.a/e'


# 1. Rename folders
platform_list=("arch-arm" "arch-arm64" "arch-x86" "arch-x86_64")
target_abi_list=("armeabi-v7a" "arm64-v8a" "x86" "x86_64")
lib_prefix_list=("arm-unknown-linux-androideabi" "aarch64-unknown-linux-android" "x86-unknown-linux-android" "x86_64-pc-linux-android")

idx=0
for platform in ${platform_list[@]}  
do  
    # set enviroment
    echo $idx
    echo "Rename from $platform to ${target_abi_list[$idx]}"
	mv $path/$platform $path/${target_abi_list[$idx]}
	
	mv $path_other/$platform $path_other/${target_abi_list[$idx]}
    
    
    
    
    # go to next platform
    idx=$[idx+1]
    
done

# Rename libs
find /cygdrive/c/Users/shenjinqi/StudioProjects/Mcpttclient/app/src/main/jni/prebuild/pjsip_mcptt -follow -name '*.a'|sed -n 's/\(.*lib.*\)-.*/mv & \1.a/e'
find /cygdrive/c/Users/shenjinqi/StudioProjects/Mcpttclient/app/src/main/jni/prebuild/pjsip_mcptt -follow -name '*.a'|sed -n 's/\(.*lib.*\)-.*/mv & \1.a/e'
find /cygdrive/c/Users/shenjinqi/StudioProjects/Mcpttclient/app/src/main/jni/prebuild/pjsip_mcptt -follow -name '*.a'|sed -n 's/\(.*lib.*\)-.*/mv & \1.a/e'
find /cygdrive/c/Users/shenjinqi/StudioProjects/Mcpttclient/app/src/main/jni/prebuild/pjsip_mcptt -follow -name '*.a'|sed -n 's/\(.*lib.*\)-.*/mv & \1.a/e'

