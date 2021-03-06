# ----------------------------------
# --- AGLib (BT Patch) - Project ---
# ----------------------------------

# --- CMake Internals ---
cmake_minimum_required	(VERSION 2.6)

# --- Project Root Name ---
project					(AGLIB_BT)

# --- Win32 Settings ---
if (WIN32 AND NOT MINGW)
	set (EXTLIBS			C:/Dev)
    set (WIN_32_EXT_GTKMM	${EXTLIBS}/gtkmm)
    set (WIN_32_EXT_DL      ${EXTLIBS}/dlfcn)
    set (WIN_32_EXT_XERCES  ${EXTLIBS}/xerces-c)

	include_directories(
		${WIN_32_EXT_GTKMM}/include
		${WIN_32_EXT_DL}/include
		${WIN_32_EXT_XERCES}/include
	)

	link_directories(
		${WIN_32_EXT_GTKMM}/lib
		${WIN_32_EXT_DL}/lib
		${WIN_32_EXT_XERCES}/lib
)
endif (WIN32 AND NOT MINGW)

if (APPLE)
	include_directories(
		/sw/include
	)

	link_directories(
		/sw/lib
	)
endif (APPLE)

# --- Unix / Mac Settings ---
if (UNIX)
	# --- Global Package Dependencies ---
	find_package			(PkgConfig	REQUIRED)
	find_package			(ZLIB		REQUIRED)
endif (UNIX)

# --- Global variables ---
set						(SRC		${AGLIB_BT_SOURCE_DIR}/src)
#set (CMAKE_CXX_FLAGS -pg)

# --- Directories ---
#add_subdirectory		(scripts)
add_subdirectory		(src)

