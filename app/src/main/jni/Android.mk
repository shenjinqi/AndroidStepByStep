# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

#LOCAL_PATH := prebuild
#LIB_PATH := $(LOCAL_PATH)/prebuild
LIB_PATH := prebuild
#ARCH_TMP := x86_64-pc
#ARCH_TMP := aarch64-unknown
ARCH_TMP := x86_64-pc
SRC_PATH := prebuild
include $(CLEAR_VARS)
LOCAL_MODULE            := libpj
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/pjlib/libpj.a
LOCAL_EXPORT_C_INCLUDES := $(SRC_PATH)/pjsip_mcptt/pjlib/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE            := libpjlib-util
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/pjlib-util/libpjlib-util.a
LOCAL_EXPORT_C_INCLUDES := $(SRC_PATH)/pjsip_mcptt/pjlib-util/include
include $(PREBUILT_STATIC_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE            := libpjsip-simple
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/pjsip/libpjsip-simple.a
LOCAL_EXPORT_C_INCLUDES := $(SRC_PATH)/pjsip_mcptt/pjsip/include
include $(PREBUILT_STATIC_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE            := libpjsdp
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/pjmedia/libpjsdp.a
LOCAL_EXPORT_C_INCLUDES := $(SRC_PATH)/pjsip_mcptt/pjmedia/include
include $(PREBUILT_STATIC_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE            := libpjsip-ua
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/pjsip/libpjsip-ua.a
LOCAL_EXPORT_C_INCLUDES := $(SRC_PATH)/pjsip_mcptt/pjsip/include
include $(PREBUILT_STATIC_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE            := libpjmedia-codec
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/pjmedia/libpjmedia-codec.a
LOCAL_EXPORT_C_INCLUDES := $(SRC_PATH)/pjsip_mcptt/pjmedia/include
include $(PREBUILT_STATIC_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE            := libpjnath
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/pjnath/libpjnath.a
LOCAL_EXPORT_C_INCLUDES := $(SRC_PATH)/pjsip_mcptt/pjnath/include
include $(PREBUILT_STATIC_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE            := libpjmedia
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/pjmedia/libpjmedia.a
LOCAL_EXPORT_C_INCLUDES := $(SRC_PATH)/pjsip_mcptt/pjmedia/include
include $(PREBUILT_STATIC_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE            := libpjsip
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/pjsip/libpjsip.a
LOCAL_EXPORT_C_INCLUDES := $(SRC_PATH)/pjsip_mcptt/pjsip/include
include $(PREBUILT_STATIC_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE            := libpjsip-mcptt
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/pjsip/libpjsip-mcptt.a
LOCAL_EXPORT_C_INCLUDES := $(SRC_PATH)/pjsip_mcptt/pjsip/include
include $(PREBUILT_STATIC_LIBRARY)
LOCAL_MODULE            := libpjsua
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/pjsip/libpjsua.a
LOCAL_EXPORT_C_INCLUDES := $(SRC_PATH)/pjsip_mcptt/pjsip/include
include $(PREBUILT_STATIC_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE            := libpjmedia-audiodev
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/pjmedia/libpjmedia-audiodev.a
LOCAL_EXPORT_C_INCLUDES := $(SRC_PATH)/pjsip_mcptt/pjmedia/include
include $(PREBUILT_STATIC_LIBRARY)
LOCAL_MODULE            := libsrtp
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/third_party/libsrtp.a
include $(PREBUILT_STATIC_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE            := libpjmedia-videodev
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/pjmedia/libpjmedia-videodev.a
LOCAL_EXPORT_C_INCLUDES := $(SRC_PATH)/pjsip_mcptt/pjmedia/include
include $(PREBUILT_STATIC_LIBRARY)
LOCAL_MODULE            := libspeex
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/third_party/libspeex.a
include $(PREBUILT_STATIC_LIBRARY)
LOCAL_MODULE            := libgsmcodec
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/third_party/libgsmcodec.a
include $(PREBUILT_STATIC_LIBRARY)
LOCAL_MODULE            := libilbccodec
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/third_party/libilbccodec.a
include $(PREBUILT_STATIC_LIBRARY)
LOCAL_MODULE            := libresample
LOCAL_SRC_FILES         := $(LIB_PATH)/pjsip_mcptt/$(TARGET_ARCH_ABI)/third_party/libresample.a
include $(PREBUILT_STATIC_LIBRARY)

LOCAL_MODULE            := lopencore-amrnb
LOCAL_SRC_FILES         := $(LIB_PATH)/other/$(TARGET_ARCH_ABI)/lib/libopencore-amrnb.a
include $(PREBUILT_STATIC_LIBRARY)
LOCAL_MODULE            := lopencore-amrwb
LOCAL_SRC_FILES         := $(LIB_PATH)/other/$(TARGET_ARCH_ABI)/lib/libopencore-amrwb.a
include $(PREBUILT_STATIC_LIBRARY)
LOCAL_MODULE            := lvo-amrwbenc
LOCAL_SRC_FILES         := $(LIB_PATH)/other/$(TARGET_ARCH_ABI)/lib/libvo-amrwbenc.a
include $(PREBUILT_STATIC_LIBRARY)


LOCAL_MODULE    := libcjson
LOCAL_SRC_FILES :=  $(LOCAL_PATH)/cJSON/cJSON.c \
                    $(LOCAL_PATH)/cJSON/cJSON_Utils.c
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := pjsipMcptt
LOCAL_C_INCLUDES    :=  $(SRC_PATH)/pjsip_mcptt/pjlib/include
LOCAL_C_INCLUDES    +=  $(SRC_PATH)/pjsip_mcptt/pjmedia/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/cJSON
# LOCAL_C_INCLUDES    +=  $(LOCAL_PATH)/android-ndk-r12b/samples/mcptt_jni_dev/jni/sip_rtp.h
LOCAL_SRC_FILES := hello-jni.cpp
LOCAL_SRC_FILES += sip_rtp.c

LOCAL_STATIC_LIBRARIES := libpjsua \
                          libpjsip-ua \
                          libpjsip-simple \
                          libpjsip-mcptt \
                          libpjsip \
                          libpjmedia-codec \
                          libpjmedia \
                          libpjmedia-audiodev \
                          libpjmedia-videodev \
                          libpjnath \
                          libpjlib-util \
                          libsrtp \
                          libspeex \
                          libgsmcodec \
                          libilbccodec \
                          libresample \
                          libpj \
                          lopencore-amrnb \
                          lopencore-amrwb \
                          lvo-amrwbenc \
                          libcjson
LOCAL_CFLAGS +=    -DPJ_M_ARM64=1
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)


#LOCAL_PATH := $(call my-dir)

#include $(CLEAR_VARS)

#LOCAL_C_INCLUDES += $(LOCAL_PATH)/cJSON


#LOCAL_MODULE    := cJSON
#LOCAL_SRC_FILES :=  $(LOCAL_PATH)/cJSON/cJSON.h \
#                    $(LOCAL_PATH)/cJSON/cJSON_Utils.h

#include $(BUILD_SHARED_LIBRARY)

LOCAL_PROGUARD_ENABLED:= disabled