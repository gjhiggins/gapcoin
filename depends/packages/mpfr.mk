package=mpfr
$(package)_version=4.0.2
$(package)_download_path=https://www.mpfr.org/mpfr-current
$(package)_file_name=$(package)-$($(package)_version).tar.bz2
$(package)_sha256_hash=c05e3f02d09e0e9019384cdd58e0f19c64e6db1fd6f5ecf77b4b1c61ca253acc
$(package)_dependencies=gmp

define $(package)_set_vars
  $(package)_config_opts=--disable-shared CC_FOR_BUILD=$(build_CC)
  $(package)_config_opts_x86_64_darwin=--with-pic
  $(package)_config_opts_x86_64_linux=--with-pic
  $(package)_config_opts_arm_linux=--with-pic
endef

define $(package)_config_cmds
  $($(package)_autoconf)
endef

define $(package)_build_cmds
  $(MAKE)
endef

define $(package)_stage_cmds
  $(MAKE) DESTDIR=$($(package)_staging_dir) install
endef