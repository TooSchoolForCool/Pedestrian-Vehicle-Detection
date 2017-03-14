#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file $(TARGET)
# 'make clean'  removes all .o and executable files
# 'make run'	build executalbe file $(TARGET) and run it ./$(TARGET)
#

# define the C compiler to use
CC = g++

# define thr remove command
RM = rm

# define any compile-time flags
CFLAGS = -Wall -g

# define any directories containing header files other than /usr/include
#
INCLUDES = `pkg-config --cflags opencv`

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
#
LFLAGS = `pkg-config --libs opencv`

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
#
LIBS =

# define the C source files
SRCS = main.cpp \
	   vetroi.cpp \
	   vetdetectorcontext.cpp \
	   vetdetectorstrategy.cpp \
	   vethaardetector.cpp \
	   vethogsvmdetector.cpp \
	   vetcolordetector.cpp \
	   vetimagetoolkit.cpp \
	   vettester.cpp \
	   vetfastvideocapture.cpp \
	   vetconcurrentqueue.cpp

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.cpp=.o)

# define the executable file 
TARGET = launch

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all: $(TARGET)
	@echo launch has been succesfully compiled

$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
#
%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) -f *.o $(TARGET)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
main.o: vettester.h vetdetectorcontext.h vetdetectorstrategy.h vetroi.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/opencv.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvdef.h
main.o: /usr/include/limits.h /usr/include/sys/cdefs.h
main.o: /usr/include/sys/_symbol_aliasing.h
main.o: /usr/include/sys/_posix_availability.h /usr/include/machine/limits.h
main.o: /usr/include/i386/limits.h /usr/include/i386/_limits.h
main.o: /usr/include/sys/syslimits.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/hal/interface.h
main.o: /usr/include/stddef.h /usr/include/_types.h /usr/include/sys/_types.h
main.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
main.o: /usr/include/sys/_pthread/_pthread_types.h
main.o: /usr/include/sys/_types/_null.h /usr/include/sys/_types/_offsetof.h
main.o: /usr/include/sys/_types/_ptrdiff_t.h
main.o: /usr/include/sys/_types/_rsize_t.h /usr/include/sys/_types/_size_t.h
main.o: /usr/include/sys/_types/_wchar_t.h /usr/include/sys/_types/_wint_t.h
main.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
main.o: /usr/include/sys/_types/_int16_t.h /usr/include/sys/_types/_int32_t.h
main.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
main.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
main.o: /usr/include/_types/_uint64_t.h /usr/include/sys/_types/_intptr_t.h
main.o: /usr/include/sys/_types/_uintptr_t.h /usr/include/_types/_intmax_t.h
main.o: /usr/include/_types/_uintmax_t.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/version.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/base.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/ptr.inl.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/neon_utils.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/traits.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/matx.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/saturate.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/fast_math.hpp
main.o: /usr/include/math.h /usr/include/Availability.h
main.o: /usr/include/AvailabilityInternal.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/bufferpool.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.inl.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/persistence.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/operations.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.inl.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/utility.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/core_c.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types_c.h
main.o: /usr/include/assert.h /usr/include/stdlib.h /usr/include/sys/wait.h
main.o: /usr/include/sys/_types/_pid_t.h /usr/include/sys/_types/_id_t.h
main.o: /usr/include/sys/signal.h /usr/include/sys/appleapiopts.h
main.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
main.o: /usr/include/machine/_mcontext.h /usr/include/i386/_mcontext.h
main.o: /usr/include/mach/i386/_structs.h
main.o: /usr/include/sys/_pthread/_pthread_attr_t.h
main.o: /usr/include/sys/_types/_sigaltstack.h
main.o: /usr/include/sys/_types/_ucontext.h
main.o: /usr/include/sys/_types/_sigset_t.h /usr/include/sys/_types/_uid_t.h
main.o: /usr/include/sys/resource.h /usr/include/sys/_types/_timeval.h
main.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
main.o: /usr/include/sys/_endian.h /usr/include/libkern/_OSByteOrder.h
main.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
main.o: /usr/include/sys/_types/_ct_rune_t.h
main.o: /usr/include/sys/_types/_rune_t.h /usr/include/machine/types.h
main.o: /usr/include/i386/types.h /usr/include/sys/_types/_dev_t.h
main.o: /usr/include/sys/_types/_mode_t.h /usr/include/string.h
main.o: /usr/include/sys/_types/_errno_t.h /usr/include/sys/_types/_ssize_t.h
main.o: /usr/include/strings.h /usr/include/secure/_string.h
main.o: /usr/include/secure/_common.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/optim.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/imgproc_c.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/types_c.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo/photo_c.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/background_segm.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking_c.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/features2d.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/miniflann.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/defines.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/config.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/detection_based_tracker.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/objdetect_c.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/affine.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d/calib3d_c.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui.hpp
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui/highgui_c.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs/imgcodecs_c.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio/videoio_c.h
main.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/ml.hpp
main.o: vethaardetector.h vetcolordetector.h vethogsvmdetector.h
main.o: vetimagetoolkit.h vetconcurrentqueue.h /usr/include/pthread.h
main.o: /usr/include/pthread/pthread_impl.h /usr/include/pthread/sched.h
main.o: /usr/include/pthread_impl.h /usr/include/time.h
main.o: /usr/include/sys/_types/_clock_t.h /usr/include/sys/_types/_time_t.h
main.o: /usr/include/sys/_types/_timespec.h
main.o: /usr/include/sys/_pthread/_pthread_cond_t.h
main.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
main.o: /usr/include/sys/_pthread/_pthread_key_t.h
main.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
main.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
main.o: /usr/include/sys/_pthread/_pthread_once_t.h
main.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
main.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
main.o: /usr/include/sys/_pthread/_pthread_t.h /usr/include/pthread/qos.h
main.o: /usr/include/sys/qos.h /usr/include/sys/_types/_mach_port_t.h
main.o: /usr/include/stdio.h /usr/include/sys/_types/_va_list.h
main.o: /usr/include/sys/stdio.h /usr/include/sys/_types/_off_t.h
main.o: /usr/include/secure/_stdio.h vetconcurrentqueue.cpp
main.o: vetfastvideocapture.h /usr/include/unistd.h /usr/include/sys/unistd.h
main.o: /usr/include/sys/_types/_posix_vdisable.h
main.o: /usr/include/sys/_types/_seek_set.h /usr/include/sys/_types/_gid_t.h
main.o: /usr/include/sys/_types/_useconds_t.h /usr/include/sys/select.h
main.o: /usr/include/sys/_types/_fd_def.h
main.o: /usr/include/sys/_types/_suseconds_t.h
main.o: /usr/include/sys/_types/_fd_setsize.h
main.o: /usr/include/sys/_types/_fd_set.h /usr/include/sys/_types/_fd_clr.h
main.o: /usr/include/sys/_types/_fd_isset.h
main.o: /usr/include/sys/_types/_fd_zero.h /usr/include/sys/_types/_fd_copy.h
main.o: /usr/include/sys/_select.h /usr/include/sys/_types/_uuid_t.h
main.o: /usr/include/gethostuuid.h
vetroi.o: vetroi.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/opencv.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvdef.h
vetroi.o: /usr/include/limits.h /usr/include/sys/cdefs.h
vetroi.o: /usr/include/sys/_symbol_aliasing.h
vetroi.o: /usr/include/sys/_posix_availability.h
vetroi.o: /usr/include/machine/limits.h /usr/include/i386/limits.h
vetroi.o: /usr/include/i386/_limits.h /usr/include/sys/syslimits.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/hal/interface.h
vetroi.o: /usr/include/stddef.h /usr/include/_types.h
vetroi.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
vetroi.o: /usr/include/i386/_types.h
vetroi.o: /usr/include/sys/_pthread/_pthread_types.h
vetroi.o: /usr/include/sys/_types/_null.h /usr/include/sys/_types/_offsetof.h
vetroi.o: /usr/include/sys/_types/_ptrdiff_t.h
vetroi.o: /usr/include/sys/_types/_rsize_t.h
vetroi.o: /usr/include/sys/_types/_size_t.h
vetroi.o: /usr/include/sys/_types/_wchar_t.h
vetroi.o: /usr/include/sys/_types/_wint_t.h /usr/include/stdint.h
vetroi.o: /usr/include/sys/_types/_int8_t.h
vetroi.o: /usr/include/sys/_types/_int16_t.h
vetroi.o: /usr/include/sys/_types/_int32_t.h
vetroi.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
vetroi.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
vetroi.o: /usr/include/_types/_uint64_t.h /usr/include/sys/_types/_intptr_t.h
vetroi.o: /usr/include/sys/_types/_uintptr_t.h
vetroi.o: /usr/include/_types/_intmax_t.h /usr/include/_types/_uintmax_t.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/version.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/base.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/ptr.inl.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/neon_utils.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/traits.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/matx.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/saturate.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/fast_math.hpp
vetroi.o: /usr/include/math.h /usr/include/Availability.h
vetroi.o: /usr/include/AvailabilityInternal.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/bufferpool.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.inl.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/persistence.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/operations.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.inl.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/utility.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/core_c.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types_c.h
vetroi.o: /usr/include/assert.h /usr/include/stdlib.h /usr/include/sys/wait.h
vetroi.o: /usr/include/sys/_types/_pid_t.h /usr/include/sys/_types/_id_t.h
vetroi.o: /usr/include/sys/signal.h /usr/include/sys/appleapiopts.h
vetroi.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
vetroi.o: /usr/include/machine/_mcontext.h /usr/include/i386/_mcontext.h
vetroi.o: /usr/include/mach/i386/_structs.h
vetroi.o: /usr/include/sys/_pthread/_pthread_attr_t.h
vetroi.o: /usr/include/sys/_types/_sigaltstack.h
vetroi.o: /usr/include/sys/_types/_ucontext.h
vetroi.o: /usr/include/sys/_types/_sigset_t.h
vetroi.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
vetroi.o: /usr/include/sys/_types/_timeval.h /usr/include/machine/endian.h
vetroi.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
vetroi.o: /usr/include/libkern/_OSByteOrder.h
vetroi.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
vetroi.o: /usr/include/sys/_types/_ct_rune_t.h
vetroi.o: /usr/include/sys/_types/_rune_t.h /usr/include/machine/types.h
vetroi.o: /usr/include/i386/types.h /usr/include/sys/_types/_dev_t.h
vetroi.o: /usr/include/sys/_types/_mode_t.h /usr/include/string.h
vetroi.o: /usr/include/sys/_types/_errno_t.h
vetroi.o: /usr/include/sys/_types/_ssize_t.h /usr/include/strings.h
vetroi.o: /usr/include/secure/_string.h /usr/include/secure/_common.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/optim.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/imgproc_c.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/types_c.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo/photo_c.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/background_segm.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking_c.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/features2d.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/miniflann.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/defines.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/config.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/detection_based_tracker.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/objdetect_c.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/affine.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d/calib3d_c.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui.hpp
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui/highgui_c.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs/imgcodecs_c.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio/videoio_c.h
vetroi.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/ml.hpp
vetdetectorcontext.o: vetdetectorcontext.h vetdetectorstrategy.h vetroi.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/opencv.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvdef.h
vetdetectorcontext.o: /usr/include/limits.h /usr/include/sys/cdefs.h
vetdetectorcontext.o: /usr/include/sys/_symbol_aliasing.h
vetdetectorcontext.o: /usr/include/sys/_posix_availability.h
vetdetectorcontext.o: /usr/include/machine/limits.h
vetdetectorcontext.o: /usr/include/i386/limits.h /usr/include/i386/_limits.h
vetdetectorcontext.o: /usr/include/sys/syslimits.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/hal/interface.h
vetdetectorcontext.o: /usr/include/stddef.h /usr/include/_types.h
vetdetectorcontext.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
vetdetectorcontext.o: /usr/include/i386/_types.h
vetdetectorcontext.o: /usr/include/sys/_pthread/_pthread_types.h
vetdetectorcontext.o: /usr/include/sys/_types/_null.h
vetdetectorcontext.o: /usr/include/sys/_types/_offsetof.h
vetdetectorcontext.o: /usr/include/sys/_types/_ptrdiff_t.h
vetdetectorcontext.o: /usr/include/sys/_types/_rsize_t.h
vetdetectorcontext.o: /usr/include/sys/_types/_size_t.h
vetdetectorcontext.o: /usr/include/sys/_types/_wchar_t.h
vetdetectorcontext.o: /usr/include/sys/_types/_wint_t.h /usr/include/stdint.h
vetdetectorcontext.o: /usr/include/sys/_types/_int8_t.h
vetdetectorcontext.o: /usr/include/sys/_types/_int16_t.h
vetdetectorcontext.o: /usr/include/sys/_types/_int32_t.h
vetdetectorcontext.o: /usr/include/sys/_types/_int64_t.h
vetdetectorcontext.o: /usr/include/_types/_uint8_t.h
vetdetectorcontext.o: /usr/include/_types/_uint16_t.h
vetdetectorcontext.o: /usr/include/_types/_uint32_t.h
vetdetectorcontext.o: /usr/include/_types/_uint64_t.h
vetdetectorcontext.o: /usr/include/sys/_types/_intptr_t.h
vetdetectorcontext.o: /usr/include/sys/_types/_uintptr_t.h
vetdetectorcontext.o: /usr/include/_types/_intmax_t.h
vetdetectorcontext.o: /usr/include/_types/_uintmax_t.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/version.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/base.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/ptr.inl.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/neon_utils.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/traits.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/matx.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/saturate.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/fast_math.hpp
vetdetectorcontext.o: /usr/include/math.h /usr/include/Availability.h
vetdetectorcontext.o: /usr/include/AvailabilityInternal.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/bufferpool.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.inl.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/persistence.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/operations.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.inl.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/utility.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/core_c.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types_c.h
vetdetectorcontext.o: /usr/include/assert.h /usr/include/stdlib.h
vetdetectorcontext.o: /usr/include/sys/wait.h
vetdetectorcontext.o: /usr/include/sys/_types/_pid_t.h
vetdetectorcontext.o: /usr/include/sys/_types/_id_t.h
vetdetectorcontext.o: /usr/include/sys/signal.h
vetdetectorcontext.o: /usr/include/sys/appleapiopts.h
vetdetectorcontext.o: /usr/include/machine/signal.h
vetdetectorcontext.o: /usr/include/i386/signal.h
vetdetectorcontext.o: /usr/include/machine/_mcontext.h
vetdetectorcontext.o: /usr/include/i386/_mcontext.h
vetdetectorcontext.o: /usr/include/mach/i386/_structs.h
vetdetectorcontext.o: /usr/include/sys/_pthread/_pthread_attr_t.h
vetdetectorcontext.o: /usr/include/sys/_types/_sigaltstack.h
vetdetectorcontext.o: /usr/include/sys/_types/_ucontext.h
vetdetectorcontext.o: /usr/include/sys/_types/_sigset_t.h
vetdetectorcontext.o: /usr/include/sys/_types/_uid_t.h
vetdetectorcontext.o: /usr/include/sys/resource.h
vetdetectorcontext.o: /usr/include/sys/_types/_timeval.h
vetdetectorcontext.o: /usr/include/machine/endian.h
vetdetectorcontext.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
vetdetectorcontext.o: /usr/include/libkern/_OSByteOrder.h
vetdetectorcontext.o: /usr/include/libkern/i386/_OSByteOrder.h
vetdetectorcontext.o: /usr/include/alloca.h
vetdetectorcontext.o: /usr/include/sys/_types/_ct_rune_t.h
vetdetectorcontext.o: /usr/include/sys/_types/_rune_t.h
vetdetectorcontext.o: /usr/include/machine/types.h /usr/include/i386/types.h
vetdetectorcontext.o: /usr/include/sys/_types/_dev_t.h
vetdetectorcontext.o: /usr/include/sys/_types/_mode_t.h /usr/include/string.h
vetdetectorcontext.o: /usr/include/sys/_types/_errno_t.h
vetdetectorcontext.o: /usr/include/sys/_types/_ssize_t.h
vetdetectorcontext.o: /usr/include/strings.h /usr/include/secure/_string.h
vetdetectorcontext.o: /usr/include/secure/_common.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/optim.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/imgproc_c.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/types_c.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo/photo_c.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/background_segm.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking_c.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/features2d.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/miniflann.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/defines.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/config.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/detection_based_tracker.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/objdetect_c.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/affine.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d/calib3d_c.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui.hpp
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui/highgui_c.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs/imgcodecs_c.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio/videoio_c.h
vetdetectorcontext.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/ml.hpp
vetdetectorcontext.o: vethaardetector.h vetcolordetector.h
vetdetectorcontext.o: vethogsvmdetector.h
vetdetectorstrategy.o: vetdetectorstrategy.h vetroi.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/opencv.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvdef.h
vetdetectorstrategy.o: /usr/include/limits.h /usr/include/sys/cdefs.h
vetdetectorstrategy.o: /usr/include/sys/_symbol_aliasing.h
vetdetectorstrategy.o: /usr/include/sys/_posix_availability.h
vetdetectorstrategy.o: /usr/include/machine/limits.h
vetdetectorstrategy.o: /usr/include/i386/limits.h /usr/include/i386/_limits.h
vetdetectorstrategy.o: /usr/include/sys/syslimits.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/hal/interface.h
vetdetectorstrategy.o: /usr/include/stddef.h /usr/include/_types.h
vetdetectorstrategy.o: /usr/include/sys/_types.h
vetdetectorstrategy.o: /usr/include/machine/_types.h
vetdetectorstrategy.o: /usr/include/i386/_types.h
vetdetectorstrategy.o: /usr/include/sys/_pthread/_pthread_types.h
vetdetectorstrategy.o: /usr/include/sys/_types/_null.h
vetdetectorstrategy.o: /usr/include/sys/_types/_offsetof.h
vetdetectorstrategy.o: /usr/include/sys/_types/_ptrdiff_t.h
vetdetectorstrategy.o: /usr/include/sys/_types/_rsize_t.h
vetdetectorstrategy.o: /usr/include/sys/_types/_size_t.h
vetdetectorstrategy.o: /usr/include/sys/_types/_wchar_t.h
vetdetectorstrategy.o: /usr/include/sys/_types/_wint_t.h
vetdetectorstrategy.o: /usr/include/stdint.h
vetdetectorstrategy.o: /usr/include/sys/_types/_int8_t.h
vetdetectorstrategy.o: /usr/include/sys/_types/_int16_t.h
vetdetectorstrategy.o: /usr/include/sys/_types/_int32_t.h
vetdetectorstrategy.o: /usr/include/sys/_types/_int64_t.h
vetdetectorstrategy.o: /usr/include/_types/_uint8_t.h
vetdetectorstrategy.o: /usr/include/_types/_uint16_t.h
vetdetectorstrategy.o: /usr/include/_types/_uint32_t.h
vetdetectorstrategy.o: /usr/include/_types/_uint64_t.h
vetdetectorstrategy.o: /usr/include/sys/_types/_intptr_t.h
vetdetectorstrategy.o: /usr/include/sys/_types/_uintptr_t.h
vetdetectorstrategy.o: /usr/include/_types/_intmax_t.h
vetdetectorstrategy.o: /usr/include/_types/_uintmax_t.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/version.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/base.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/ptr.inl.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/neon_utils.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/traits.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/matx.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/saturate.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/fast_math.hpp
vetdetectorstrategy.o: /usr/include/math.h /usr/include/Availability.h
vetdetectorstrategy.o: /usr/include/AvailabilityInternal.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/bufferpool.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.inl.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/persistence.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/operations.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.inl.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/utility.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/core_c.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types_c.h
vetdetectorstrategy.o: /usr/include/assert.h /usr/include/stdlib.h
vetdetectorstrategy.o: /usr/include/sys/wait.h
vetdetectorstrategy.o: /usr/include/sys/_types/_pid_t.h
vetdetectorstrategy.o: /usr/include/sys/_types/_id_t.h
vetdetectorstrategy.o: /usr/include/sys/signal.h
vetdetectorstrategy.o: /usr/include/sys/appleapiopts.h
vetdetectorstrategy.o: /usr/include/machine/signal.h
vetdetectorstrategy.o: /usr/include/i386/signal.h
vetdetectorstrategy.o: /usr/include/machine/_mcontext.h
vetdetectorstrategy.o: /usr/include/i386/_mcontext.h
vetdetectorstrategy.o: /usr/include/mach/i386/_structs.h
vetdetectorstrategy.o: /usr/include/sys/_pthread/_pthread_attr_t.h
vetdetectorstrategy.o: /usr/include/sys/_types/_sigaltstack.h
vetdetectorstrategy.o: /usr/include/sys/_types/_ucontext.h
vetdetectorstrategy.o: /usr/include/sys/_types/_sigset_t.h
vetdetectorstrategy.o: /usr/include/sys/_types/_uid_t.h
vetdetectorstrategy.o: /usr/include/sys/resource.h
vetdetectorstrategy.o: /usr/include/sys/_types/_timeval.h
vetdetectorstrategy.o: /usr/include/machine/endian.h
vetdetectorstrategy.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
vetdetectorstrategy.o: /usr/include/libkern/_OSByteOrder.h
vetdetectorstrategy.o: /usr/include/libkern/i386/_OSByteOrder.h
vetdetectorstrategy.o: /usr/include/alloca.h
vetdetectorstrategy.o: /usr/include/sys/_types/_ct_rune_t.h
vetdetectorstrategy.o: /usr/include/sys/_types/_rune_t.h
vetdetectorstrategy.o: /usr/include/machine/types.h /usr/include/i386/types.h
vetdetectorstrategy.o: /usr/include/sys/_types/_dev_t.h
vetdetectorstrategy.o: /usr/include/sys/_types/_mode_t.h
vetdetectorstrategy.o: /usr/include/string.h
vetdetectorstrategy.o: /usr/include/sys/_types/_errno_t.h
vetdetectorstrategy.o: /usr/include/sys/_types/_ssize_t.h
vetdetectorstrategy.o: /usr/include/strings.h /usr/include/secure/_string.h
vetdetectorstrategy.o: /usr/include/secure/_common.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/optim.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/imgproc_c.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/types_c.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo/photo_c.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/background_segm.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking_c.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/features2d.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/miniflann.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/defines.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/config.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/detection_based_tracker.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/objdetect_c.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/affine.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d/calib3d_c.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui.hpp
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui/highgui_c.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs/imgcodecs_c.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio/videoio_c.h
vetdetectorstrategy.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/ml.hpp
vethaardetector.o: vethaardetector.h vetdetectorstrategy.h vetroi.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/opencv.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvdef.h
vethaardetector.o: /usr/include/limits.h /usr/include/sys/cdefs.h
vethaardetector.o: /usr/include/sys/_symbol_aliasing.h
vethaardetector.o: /usr/include/sys/_posix_availability.h
vethaardetector.o: /usr/include/machine/limits.h /usr/include/i386/limits.h
vethaardetector.o: /usr/include/i386/_limits.h /usr/include/sys/syslimits.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/hal/interface.h
vethaardetector.o: /usr/include/stddef.h /usr/include/_types.h
vethaardetector.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
vethaardetector.o: /usr/include/i386/_types.h
vethaardetector.o: /usr/include/sys/_pthread/_pthread_types.h
vethaardetector.o: /usr/include/sys/_types/_null.h
vethaardetector.o: /usr/include/sys/_types/_offsetof.h
vethaardetector.o: /usr/include/sys/_types/_ptrdiff_t.h
vethaardetector.o: /usr/include/sys/_types/_rsize_t.h
vethaardetector.o: /usr/include/sys/_types/_size_t.h
vethaardetector.o: /usr/include/sys/_types/_wchar_t.h
vethaardetector.o: /usr/include/sys/_types/_wint_t.h /usr/include/stdint.h
vethaardetector.o: /usr/include/sys/_types/_int8_t.h
vethaardetector.o: /usr/include/sys/_types/_int16_t.h
vethaardetector.o: /usr/include/sys/_types/_int32_t.h
vethaardetector.o: /usr/include/sys/_types/_int64_t.h
vethaardetector.o: /usr/include/_types/_uint8_t.h
vethaardetector.o: /usr/include/_types/_uint16_t.h
vethaardetector.o: /usr/include/_types/_uint32_t.h
vethaardetector.o: /usr/include/_types/_uint64_t.h
vethaardetector.o: /usr/include/sys/_types/_intptr_t.h
vethaardetector.o: /usr/include/sys/_types/_uintptr_t.h
vethaardetector.o: /usr/include/_types/_intmax_t.h
vethaardetector.o: /usr/include/_types/_uintmax_t.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/version.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/base.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/ptr.inl.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/neon_utils.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/traits.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/matx.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/saturate.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/fast_math.hpp
vethaardetector.o: /usr/include/math.h /usr/include/Availability.h
vethaardetector.o: /usr/include/AvailabilityInternal.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/bufferpool.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.inl.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/persistence.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/operations.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.inl.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/utility.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/core_c.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types_c.h
vethaardetector.o: /usr/include/assert.h /usr/include/stdlib.h
vethaardetector.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
vethaardetector.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
vethaardetector.o: /usr/include/sys/appleapiopts.h
vethaardetector.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
vethaardetector.o: /usr/include/machine/_mcontext.h
vethaardetector.o: /usr/include/i386/_mcontext.h
vethaardetector.o: /usr/include/mach/i386/_structs.h
vethaardetector.o: /usr/include/sys/_pthread/_pthread_attr_t.h
vethaardetector.o: /usr/include/sys/_types/_sigaltstack.h
vethaardetector.o: /usr/include/sys/_types/_ucontext.h
vethaardetector.o: /usr/include/sys/_types/_sigset_t.h
vethaardetector.o: /usr/include/sys/_types/_uid_t.h
vethaardetector.o: /usr/include/sys/resource.h
vethaardetector.o: /usr/include/sys/_types/_timeval.h
vethaardetector.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
vethaardetector.o: /usr/include/sys/_endian.h
vethaardetector.o: /usr/include/libkern/_OSByteOrder.h
vethaardetector.o: /usr/include/libkern/i386/_OSByteOrder.h
vethaardetector.o: /usr/include/alloca.h /usr/include/sys/_types/_ct_rune_t.h
vethaardetector.o: /usr/include/sys/_types/_rune_t.h
vethaardetector.o: /usr/include/machine/types.h /usr/include/i386/types.h
vethaardetector.o: /usr/include/sys/_types/_dev_t.h
vethaardetector.o: /usr/include/sys/_types/_mode_t.h /usr/include/string.h
vethaardetector.o: /usr/include/sys/_types/_errno_t.h
vethaardetector.o: /usr/include/sys/_types/_ssize_t.h /usr/include/strings.h
vethaardetector.o: /usr/include/secure/_string.h
vethaardetector.o: /usr/include/secure/_common.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/optim.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/imgproc_c.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/types_c.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo/photo_c.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/background_segm.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking_c.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/features2d.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/miniflann.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/defines.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/config.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/detection_based_tracker.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/objdetect_c.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/affine.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d/calib3d_c.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui.hpp
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui/highgui_c.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs/imgcodecs_c.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio/videoio_c.h
vethaardetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/ml.hpp
vethogsvmdetector.o: vethogsvmdetector.h vetdetectorstrategy.h vetroi.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/opencv.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvdef.h
vethogsvmdetector.o: /usr/include/limits.h /usr/include/sys/cdefs.h
vethogsvmdetector.o: /usr/include/sys/_symbol_aliasing.h
vethogsvmdetector.o: /usr/include/sys/_posix_availability.h
vethogsvmdetector.o: /usr/include/machine/limits.h /usr/include/i386/limits.h
vethogsvmdetector.o: /usr/include/i386/_limits.h /usr/include/sys/syslimits.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/hal/interface.h
vethogsvmdetector.o: /usr/include/stddef.h /usr/include/_types.h
vethogsvmdetector.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
vethogsvmdetector.o: /usr/include/i386/_types.h
vethogsvmdetector.o: /usr/include/sys/_pthread/_pthread_types.h
vethogsvmdetector.o: /usr/include/sys/_types/_null.h
vethogsvmdetector.o: /usr/include/sys/_types/_offsetof.h
vethogsvmdetector.o: /usr/include/sys/_types/_ptrdiff_t.h
vethogsvmdetector.o: /usr/include/sys/_types/_rsize_t.h
vethogsvmdetector.o: /usr/include/sys/_types/_size_t.h
vethogsvmdetector.o: /usr/include/sys/_types/_wchar_t.h
vethogsvmdetector.o: /usr/include/sys/_types/_wint_t.h /usr/include/stdint.h
vethogsvmdetector.o: /usr/include/sys/_types/_int8_t.h
vethogsvmdetector.o: /usr/include/sys/_types/_int16_t.h
vethogsvmdetector.o: /usr/include/sys/_types/_int32_t.h
vethogsvmdetector.o: /usr/include/sys/_types/_int64_t.h
vethogsvmdetector.o: /usr/include/_types/_uint8_t.h
vethogsvmdetector.o: /usr/include/_types/_uint16_t.h
vethogsvmdetector.o: /usr/include/_types/_uint32_t.h
vethogsvmdetector.o: /usr/include/_types/_uint64_t.h
vethogsvmdetector.o: /usr/include/sys/_types/_intptr_t.h
vethogsvmdetector.o: /usr/include/sys/_types/_uintptr_t.h
vethogsvmdetector.o: /usr/include/_types/_intmax_t.h
vethogsvmdetector.o: /usr/include/_types/_uintmax_t.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/version.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/base.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/ptr.inl.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/neon_utils.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/traits.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/matx.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/saturate.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/fast_math.hpp
vethogsvmdetector.o: /usr/include/math.h /usr/include/Availability.h
vethogsvmdetector.o: /usr/include/AvailabilityInternal.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/bufferpool.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.inl.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/persistence.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/operations.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.inl.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/utility.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/core_c.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types_c.h
vethogsvmdetector.o: /usr/include/assert.h /usr/include/stdlib.h
vethogsvmdetector.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
vethogsvmdetector.o: /usr/include/sys/_types/_id_t.h
vethogsvmdetector.o: /usr/include/sys/signal.h
vethogsvmdetector.o: /usr/include/sys/appleapiopts.h
vethogsvmdetector.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
vethogsvmdetector.o: /usr/include/machine/_mcontext.h
vethogsvmdetector.o: /usr/include/i386/_mcontext.h
vethogsvmdetector.o: /usr/include/mach/i386/_structs.h
vethogsvmdetector.o: /usr/include/sys/_pthread/_pthread_attr_t.h
vethogsvmdetector.o: /usr/include/sys/_types/_sigaltstack.h
vethogsvmdetector.o: /usr/include/sys/_types/_ucontext.h
vethogsvmdetector.o: /usr/include/sys/_types/_sigset_t.h
vethogsvmdetector.o: /usr/include/sys/_types/_uid_t.h
vethogsvmdetector.o: /usr/include/sys/resource.h
vethogsvmdetector.o: /usr/include/sys/_types/_timeval.h
vethogsvmdetector.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
vethogsvmdetector.o: /usr/include/sys/_endian.h
vethogsvmdetector.o: /usr/include/libkern/_OSByteOrder.h
vethogsvmdetector.o: /usr/include/libkern/i386/_OSByteOrder.h
vethogsvmdetector.o: /usr/include/alloca.h
vethogsvmdetector.o: /usr/include/sys/_types/_ct_rune_t.h
vethogsvmdetector.o: /usr/include/sys/_types/_rune_t.h
vethogsvmdetector.o: /usr/include/machine/types.h /usr/include/i386/types.h
vethogsvmdetector.o: /usr/include/sys/_types/_dev_t.h
vethogsvmdetector.o: /usr/include/sys/_types/_mode_t.h /usr/include/string.h
vethogsvmdetector.o: /usr/include/sys/_types/_errno_t.h
vethogsvmdetector.o: /usr/include/sys/_types/_ssize_t.h
vethogsvmdetector.o: /usr/include/strings.h /usr/include/secure/_string.h
vethogsvmdetector.o: /usr/include/secure/_common.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/optim.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/imgproc_c.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/types_c.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo/photo_c.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/background_segm.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking_c.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/features2d.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/miniflann.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/defines.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/config.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/detection_based_tracker.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/objdetect_c.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/affine.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d/calib3d_c.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui.hpp
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui/highgui_c.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs/imgcodecs_c.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio/videoio_c.h
vethogsvmdetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/ml.hpp
vetcolordetector.o: vetcolordetector.h vetdetectorstrategy.h vetroi.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/opencv.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvdef.h
vetcolordetector.o: /usr/include/limits.h /usr/include/sys/cdefs.h
vetcolordetector.o: /usr/include/sys/_symbol_aliasing.h
vetcolordetector.o: /usr/include/sys/_posix_availability.h
vetcolordetector.o: /usr/include/machine/limits.h /usr/include/i386/limits.h
vetcolordetector.o: /usr/include/i386/_limits.h /usr/include/sys/syslimits.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/hal/interface.h
vetcolordetector.o: /usr/include/stddef.h /usr/include/_types.h
vetcolordetector.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
vetcolordetector.o: /usr/include/i386/_types.h
vetcolordetector.o: /usr/include/sys/_pthread/_pthread_types.h
vetcolordetector.o: /usr/include/sys/_types/_null.h
vetcolordetector.o: /usr/include/sys/_types/_offsetof.h
vetcolordetector.o: /usr/include/sys/_types/_ptrdiff_t.h
vetcolordetector.o: /usr/include/sys/_types/_rsize_t.h
vetcolordetector.o: /usr/include/sys/_types/_size_t.h
vetcolordetector.o: /usr/include/sys/_types/_wchar_t.h
vetcolordetector.o: /usr/include/sys/_types/_wint_t.h /usr/include/stdint.h
vetcolordetector.o: /usr/include/sys/_types/_int8_t.h
vetcolordetector.o: /usr/include/sys/_types/_int16_t.h
vetcolordetector.o: /usr/include/sys/_types/_int32_t.h
vetcolordetector.o: /usr/include/sys/_types/_int64_t.h
vetcolordetector.o: /usr/include/_types/_uint8_t.h
vetcolordetector.o: /usr/include/_types/_uint16_t.h
vetcolordetector.o: /usr/include/_types/_uint32_t.h
vetcolordetector.o: /usr/include/_types/_uint64_t.h
vetcolordetector.o: /usr/include/sys/_types/_intptr_t.h
vetcolordetector.o: /usr/include/sys/_types/_uintptr_t.h
vetcolordetector.o: /usr/include/_types/_intmax_t.h
vetcolordetector.o: /usr/include/_types/_uintmax_t.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/version.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/base.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/ptr.inl.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/neon_utils.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/traits.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/matx.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/saturate.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/fast_math.hpp
vetcolordetector.o: /usr/include/math.h /usr/include/Availability.h
vetcolordetector.o: /usr/include/AvailabilityInternal.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/bufferpool.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.inl.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/persistence.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/operations.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.inl.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/utility.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/core_c.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types_c.h
vetcolordetector.o: /usr/include/assert.h /usr/include/stdlib.h
vetcolordetector.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
vetcolordetector.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
vetcolordetector.o: /usr/include/sys/appleapiopts.h
vetcolordetector.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
vetcolordetector.o: /usr/include/machine/_mcontext.h
vetcolordetector.o: /usr/include/i386/_mcontext.h
vetcolordetector.o: /usr/include/mach/i386/_structs.h
vetcolordetector.o: /usr/include/sys/_pthread/_pthread_attr_t.h
vetcolordetector.o: /usr/include/sys/_types/_sigaltstack.h
vetcolordetector.o: /usr/include/sys/_types/_ucontext.h
vetcolordetector.o: /usr/include/sys/_types/_sigset_t.h
vetcolordetector.o: /usr/include/sys/_types/_uid_t.h
vetcolordetector.o: /usr/include/sys/resource.h
vetcolordetector.o: /usr/include/sys/_types/_timeval.h
vetcolordetector.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
vetcolordetector.o: /usr/include/sys/_endian.h
vetcolordetector.o: /usr/include/libkern/_OSByteOrder.h
vetcolordetector.o: /usr/include/libkern/i386/_OSByteOrder.h
vetcolordetector.o: /usr/include/alloca.h
vetcolordetector.o: /usr/include/sys/_types/_ct_rune_t.h
vetcolordetector.o: /usr/include/sys/_types/_rune_t.h
vetcolordetector.o: /usr/include/machine/types.h /usr/include/i386/types.h
vetcolordetector.o: /usr/include/sys/_types/_dev_t.h
vetcolordetector.o: /usr/include/sys/_types/_mode_t.h /usr/include/string.h
vetcolordetector.o: /usr/include/sys/_types/_errno_t.h
vetcolordetector.o: /usr/include/sys/_types/_ssize_t.h /usr/include/strings.h
vetcolordetector.o: /usr/include/secure/_string.h
vetcolordetector.o: /usr/include/secure/_common.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/optim.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/imgproc_c.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/types_c.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo/photo_c.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/background_segm.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking_c.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/features2d.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/miniflann.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/defines.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/config.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/detection_based_tracker.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/objdetect_c.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/affine.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d/calib3d_c.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui.hpp
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui/highgui_c.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs/imgcodecs_c.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio/videoio_c.h
vetcolordetector.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/ml.hpp
vetimagetoolkit.o: vetimagetoolkit.h vetroi.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/opencv.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvdef.h
vetimagetoolkit.o: /usr/include/limits.h /usr/include/sys/cdefs.h
vetimagetoolkit.o: /usr/include/sys/_symbol_aliasing.h
vetimagetoolkit.o: /usr/include/sys/_posix_availability.h
vetimagetoolkit.o: /usr/include/machine/limits.h /usr/include/i386/limits.h
vetimagetoolkit.o: /usr/include/i386/_limits.h /usr/include/sys/syslimits.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/hal/interface.h
vetimagetoolkit.o: /usr/include/stddef.h /usr/include/_types.h
vetimagetoolkit.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
vetimagetoolkit.o: /usr/include/i386/_types.h
vetimagetoolkit.o: /usr/include/sys/_pthread/_pthread_types.h
vetimagetoolkit.o: /usr/include/sys/_types/_null.h
vetimagetoolkit.o: /usr/include/sys/_types/_offsetof.h
vetimagetoolkit.o: /usr/include/sys/_types/_ptrdiff_t.h
vetimagetoolkit.o: /usr/include/sys/_types/_rsize_t.h
vetimagetoolkit.o: /usr/include/sys/_types/_size_t.h
vetimagetoolkit.o: /usr/include/sys/_types/_wchar_t.h
vetimagetoolkit.o: /usr/include/sys/_types/_wint_t.h /usr/include/stdint.h
vetimagetoolkit.o: /usr/include/sys/_types/_int8_t.h
vetimagetoolkit.o: /usr/include/sys/_types/_int16_t.h
vetimagetoolkit.o: /usr/include/sys/_types/_int32_t.h
vetimagetoolkit.o: /usr/include/sys/_types/_int64_t.h
vetimagetoolkit.o: /usr/include/_types/_uint8_t.h
vetimagetoolkit.o: /usr/include/_types/_uint16_t.h
vetimagetoolkit.o: /usr/include/_types/_uint32_t.h
vetimagetoolkit.o: /usr/include/_types/_uint64_t.h
vetimagetoolkit.o: /usr/include/sys/_types/_intptr_t.h
vetimagetoolkit.o: /usr/include/sys/_types/_uintptr_t.h
vetimagetoolkit.o: /usr/include/_types/_intmax_t.h
vetimagetoolkit.o: /usr/include/_types/_uintmax_t.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/version.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/base.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/ptr.inl.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/neon_utils.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/traits.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/matx.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/saturate.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/fast_math.hpp
vetimagetoolkit.o: /usr/include/math.h /usr/include/Availability.h
vetimagetoolkit.o: /usr/include/AvailabilityInternal.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/bufferpool.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.inl.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/persistence.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/operations.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.inl.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/utility.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/core_c.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types_c.h
vetimagetoolkit.o: /usr/include/assert.h /usr/include/stdlib.h
vetimagetoolkit.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
vetimagetoolkit.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
vetimagetoolkit.o: /usr/include/sys/appleapiopts.h
vetimagetoolkit.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
vetimagetoolkit.o: /usr/include/machine/_mcontext.h
vetimagetoolkit.o: /usr/include/i386/_mcontext.h
vetimagetoolkit.o: /usr/include/mach/i386/_structs.h
vetimagetoolkit.o: /usr/include/sys/_pthread/_pthread_attr_t.h
vetimagetoolkit.o: /usr/include/sys/_types/_sigaltstack.h
vetimagetoolkit.o: /usr/include/sys/_types/_ucontext.h
vetimagetoolkit.o: /usr/include/sys/_types/_sigset_t.h
vetimagetoolkit.o: /usr/include/sys/_types/_uid_t.h
vetimagetoolkit.o: /usr/include/sys/resource.h
vetimagetoolkit.o: /usr/include/sys/_types/_timeval.h
vetimagetoolkit.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
vetimagetoolkit.o: /usr/include/sys/_endian.h
vetimagetoolkit.o: /usr/include/libkern/_OSByteOrder.h
vetimagetoolkit.o: /usr/include/libkern/i386/_OSByteOrder.h
vetimagetoolkit.o: /usr/include/alloca.h /usr/include/sys/_types/_ct_rune_t.h
vetimagetoolkit.o: /usr/include/sys/_types/_rune_t.h
vetimagetoolkit.o: /usr/include/machine/types.h /usr/include/i386/types.h
vetimagetoolkit.o: /usr/include/sys/_types/_dev_t.h
vetimagetoolkit.o: /usr/include/sys/_types/_mode_t.h /usr/include/string.h
vetimagetoolkit.o: /usr/include/sys/_types/_errno_t.h
vetimagetoolkit.o: /usr/include/sys/_types/_ssize_t.h /usr/include/strings.h
vetimagetoolkit.o: /usr/include/secure/_string.h
vetimagetoolkit.o: /usr/include/secure/_common.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/optim.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/imgproc_c.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/types_c.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo/photo_c.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/background_segm.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking_c.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/features2d.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/miniflann.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/defines.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/config.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/detection_based_tracker.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/objdetect_c.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/affine.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d/calib3d_c.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui.hpp
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui/highgui_c.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs/imgcodecs_c.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio/videoio_c.h
vetimagetoolkit.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/ml.hpp
vettester.o: vettester.h vetdetectorcontext.h vetdetectorstrategy.h vetroi.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/opencv.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvdef.h
vettester.o: /usr/include/limits.h /usr/include/sys/cdefs.h
vettester.o: /usr/include/sys/_symbol_aliasing.h
vettester.o: /usr/include/sys/_posix_availability.h
vettester.o: /usr/include/machine/limits.h /usr/include/i386/limits.h
vettester.o: /usr/include/i386/_limits.h /usr/include/sys/syslimits.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/hal/interface.h
vettester.o: /usr/include/stddef.h /usr/include/_types.h
vettester.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
vettester.o: /usr/include/i386/_types.h
vettester.o: /usr/include/sys/_pthread/_pthread_types.h
vettester.o: /usr/include/sys/_types/_null.h
vettester.o: /usr/include/sys/_types/_offsetof.h
vettester.o: /usr/include/sys/_types/_ptrdiff_t.h
vettester.o: /usr/include/sys/_types/_rsize_t.h
vettester.o: /usr/include/sys/_types/_size_t.h
vettester.o: /usr/include/sys/_types/_wchar_t.h
vettester.o: /usr/include/sys/_types/_wint_t.h /usr/include/stdint.h
vettester.o: /usr/include/sys/_types/_int8_t.h
vettester.o: /usr/include/sys/_types/_int16_t.h
vettester.o: /usr/include/sys/_types/_int32_t.h
vettester.o: /usr/include/sys/_types/_int64_t.h
vettester.o: /usr/include/_types/_uint8_t.h /usr/include/_types/_uint16_t.h
vettester.o: /usr/include/_types/_uint32_t.h /usr/include/_types/_uint64_t.h
vettester.o: /usr/include/sys/_types/_intptr_t.h
vettester.o: /usr/include/sys/_types/_uintptr_t.h
vettester.o: /usr/include/_types/_intmax_t.h /usr/include/_types/_uintmax_t.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/version.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/base.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/ptr.inl.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/neon_utils.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/traits.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/matx.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/saturate.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/fast_math.hpp
vettester.o: /usr/include/math.h /usr/include/Availability.h
vettester.o: /usr/include/AvailabilityInternal.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/bufferpool.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.inl.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/persistence.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/operations.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.inl.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/utility.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/core_c.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types_c.h
vettester.o: /usr/include/assert.h /usr/include/stdlib.h
vettester.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
vettester.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
vettester.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
vettester.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
vettester.o: /usr/include/i386/_mcontext.h /usr/include/mach/i386/_structs.h
vettester.o: /usr/include/sys/_pthread/_pthread_attr_t.h
vettester.o: /usr/include/sys/_types/_sigaltstack.h
vettester.o: /usr/include/sys/_types/_ucontext.h
vettester.o: /usr/include/sys/_types/_sigset_t.h
vettester.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
vettester.o: /usr/include/sys/_types/_timeval.h /usr/include/machine/endian.h
vettester.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
vettester.o: /usr/include/libkern/_OSByteOrder.h
vettester.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
vettester.o: /usr/include/sys/_types/_ct_rune_t.h
vettester.o: /usr/include/sys/_types/_rune_t.h /usr/include/machine/types.h
vettester.o: /usr/include/i386/types.h /usr/include/sys/_types/_dev_t.h
vettester.o: /usr/include/sys/_types/_mode_t.h /usr/include/string.h
vettester.o: /usr/include/sys/_types/_errno_t.h
vettester.o: /usr/include/sys/_types/_ssize_t.h /usr/include/strings.h
vettester.o: /usr/include/secure/_string.h /usr/include/secure/_common.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/optim.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/imgproc_c.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/types_c.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo/photo_c.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/background_segm.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking_c.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/features2d.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/miniflann.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/defines.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/config.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/detection_based_tracker.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/objdetect_c.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/affine.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d/calib3d_c.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui.hpp
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui/highgui_c.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs/imgcodecs_c.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio/videoio_c.h
vettester.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/ml.hpp
vettester.o: vethaardetector.h vetcolordetector.h vethogsvmdetector.h
vettester.o: vetimagetoolkit.h vetconcurrentqueue.h /usr/include/pthread.h
vettester.o: /usr/include/pthread/pthread_impl.h /usr/include/pthread/sched.h
vettester.o: /usr/include/pthread_impl.h /usr/include/time.h
vettester.o: /usr/include/sys/_types/_clock_t.h
vettester.o: /usr/include/sys/_types/_time_t.h
vettester.o: /usr/include/sys/_types/_timespec.h
vettester.o: /usr/include/sys/_pthread/_pthread_cond_t.h
vettester.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
vettester.o: /usr/include/sys/_pthread/_pthread_key_t.h
vettester.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
vettester.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
vettester.o: /usr/include/sys/_pthread/_pthread_once_t.h
vettester.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
vettester.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
vettester.o: /usr/include/sys/_pthread/_pthread_t.h
vettester.o: /usr/include/pthread/qos.h /usr/include/sys/qos.h
vettester.o: /usr/include/sys/_types/_mach_port_t.h /usr/include/stdio.h
vettester.o: /usr/include/sys/_types/_va_list.h /usr/include/sys/stdio.h
vettester.o: /usr/include/sys/_types/_off_t.h /usr/include/secure/_stdio.h
vettester.o: vetconcurrentqueue.cpp vetfastvideocapture.h
vettester.o: /usr/include/unistd.h /usr/include/sys/unistd.h
vettester.o: /usr/include/sys/_types/_posix_vdisable.h
vettester.o: /usr/include/sys/_types/_seek_set.h
vettester.o: /usr/include/sys/_types/_gid_t.h
vettester.o: /usr/include/sys/_types/_useconds_t.h /usr/include/sys/select.h
vettester.o: /usr/include/sys/_types/_fd_def.h
vettester.o: /usr/include/sys/_types/_suseconds_t.h
vettester.o: /usr/include/sys/_types/_fd_setsize.h
vettester.o: /usr/include/sys/_types/_fd_set.h
vettester.o: /usr/include/sys/_types/_fd_clr.h
vettester.o: /usr/include/sys/_types/_fd_isset.h
vettester.o: /usr/include/sys/_types/_fd_zero.h
vettester.o: /usr/include/sys/_types/_fd_copy.h /usr/include/sys/_select.h
vettester.o: /usr/include/sys/_types/_uuid_t.h /usr/include/gethostuuid.h
vetfastvideocapture.o: vetfastvideocapture.h vetconcurrentqueue.h
vetfastvideocapture.o: /usr/include/pthread.h /usr/include/_types.h
vetfastvideocapture.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
vetfastvideocapture.o: /usr/include/sys/_symbol_aliasing.h
vetfastvideocapture.o: /usr/include/sys/_posix_availability.h
vetfastvideocapture.o: /usr/include/machine/_types.h
vetfastvideocapture.o: /usr/include/i386/_types.h
vetfastvideocapture.o: /usr/include/sys/_pthread/_pthread_types.h
vetfastvideocapture.o: /usr/include/pthread/pthread_impl.h
vetfastvideocapture.o: /usr/include/pthread/sched.h
vetfastvideocapture.o: /usr/include/pthread_impl.h /usr/include/time.h
vetfastvideocapture.o: /usr/include/sys/_types/_clock_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_null.h
vetfastvideocapture.o: /usr/include/sys/_types/_size_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_time_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_timespec.h
vetfastvideocapture.o: /usr/include/sys/_pthread/_pthread_attr_t.h
vetfastvideocapture.o: /usr/include/sys/_pthread/_pthread_cond_t.h
vetfastvideocapture.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
vetfastvideocapture.o: /usr/include/sys/_pthread/_pthread_key_t.h
vetfastvideocapture.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
vetfastvideocapture.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
vetfastvideocapture.o: /usr/include/sys/_pthread/_pthread_once_t.h
vetfastvideocapture.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
vetfastvideocapture.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
vetfastvideocapture.o: /usr/include/sys/_pthread/_pthread_t.h
vetfastvideocapture.o: /usr/include/pthread/qos.h /usr/include/Availability.h
vetfastvideocapture.o: /usr/include/AvailabilityInternal.h
vetfastvideocapture.o: /usr/include/sys/qos.h
vetfastvideocapture.o: /usr/include/sys/_types/_mach_port_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_sigset_t.h
vetfastvideocapture.o: /usr/include/stdio.h
vetfastvideocapture.o: /usr/include/sys/_types/_va_list.h
vetfastvideocapture.o: /usr/include/sys/stdio.h
vetfastvideocapture.o: /usr/include/sys/_types/_off_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_ssize_t.h
vetfastvideocapture.o: /usr/include/secure/_stdio.h
vetfastvideocapture.o: /usr/include/secure/_common.h vetconcurrentqueue.cpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/opencv.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvdef.h
vetfastvideocapture.o: /usr/include/limits.h /usr/include/machine/limits.h
vetfastvideocapture.o: /usr/include/i386/limits.h /usr/include/i386/_limits.h
vetfastvideocapture.o: /usr/include/sys/syslimits.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/hal/interface.h
vetfastvideocapture.o: /usr/include/stddef.h
vetfastvideocapture.o: /usr/include/sys/_types/_offsetof.h
vetfastvideocapture.o: /usr/include/sys/_types/_ptrdiff_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_rsize_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_wchar_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_wint_t.h
vetfastvideocapture.o: /usr/include/stdint.h
vetfastvideocapture.o: /usr/include/sys/_types/_int8_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_int16_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_int32_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_int64_t.h
vetfastvideocapture.o: /usr/include/_types/_uint8_t.h
vetfastvideocapture.o: /usr/include/_types/_uint16_t.h
vetfastvideocapture.o: /usr/include/_types/_uint32_t.h
vetfastvideocapture.o: /usr/include/_types/_uint64_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_intptr_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_uintptr_t.h
vetfastvideocapture.o: /usr/include/_types/_intmax_t.h
vetfastvideocapture.o: /usr/include/_types/_uintmax_t.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/version.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/base.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/ptr.inl.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/neon_utils.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/traits.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/matx.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/saturate.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/fast_math.hpp
vetfastvideocapture.o: /usr/include/math.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/bufferpool.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/mat.inl.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/persistence.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/operations.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/cvstd.inl.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/utility.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/core_c.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/types_c.h
vetfastvideocapture.o: /usr/include/assert.h /usr/include/stdlib.h
vetfastvideocapture.o: /usr/include/sys/wait.h
vetfastvideocapture.o: /usr/include/sys/_types/_pid_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_id_t.h
vetfastvideocapture.o: /usr/include/sys/signal.h
vetfastvideocapture.o: /usr/include/sys/appleapiopts.h
vetfastvideocapture.o: /usr/include/machine/signal.h
vetfastvideocapture.o: /usr/include/i386/signal.h
vetfastvideocapture.o: /usr/include/machine/_mcontext.h
vetfastvideocapture.o: /usr/include/i386/_mcontext.h
vetfastvideocapture.o: /usr/include/mach/i386/_structs.h
vetfastvideocapture.o: /usr/include/sys/_types/_sigaltstack.h
vetfastvideocapture.o: /usr/include/sys/_types/_ucontext.h
vetfastvideocapture.o: /usr/include/sys/_types/_uid_t.h
vetfastvideocapture.o: /usr/include/sys/resource.h
vetfastvideocapture.o: /usr/include/sys/_types/_timeval.h
vetfastvideocapture.o: /usr/include/machine/endian.h
vetfastvideocapture.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
vetfastvideocapture.o: /usr/include/libkern/_OSByteOrder.h
vetfastvideocapture.o: /usr/include/libkern/i386/_OSByteOrder.h
vetfastvideocapture.o: /usr/include/alloca.h
vetfastvideocapture.o: /usr/include/sys/_types/_ct_rune_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_rune_t.h
vetfastvideocapture.o: /usr/include/machine/types.h /usr/include/i386/types.h
vetfastvideocapture.o: /usr/include/sys/_types/_dev_t.h
vetfastvideocapture.o: /usr/include/sys/_types/_mode_t.h
vetfastvideocapture.o: /usr/include/string.h
vetfastvideocapture.o: /usr/include/sys/_types/_errno_t.h
vetfastvideocapture.o: /usr/include/strings.h /usr/include/secure/_string.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/optim.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/imgproc_c.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgproc/types_c.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/photo/photo_c.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/background_segm.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/video/tracking_c.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/features2d.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/miniflann.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/defines.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/flann/config.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/detection_based_tracker.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/objdetect/objdetect_c.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/core/affine.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/calib3d/calib3d_c.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui.hpp
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/highgui/highgui_c.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/imgcodecs/imgcodecs_c.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/videoio/videoio_c.h
vetfastvideocapture.o: /usr/local/Cellar/opencv3/3.1.0_3/include/opencv2/ml.hpp
