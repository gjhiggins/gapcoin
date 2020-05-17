package=qrencode
$(package)_version=4.0.2
$(package)_download_path=https://fukuchi.org/works/qrencode/
$(package)_file_name=$(package)-$($(package)_version).tar.bz2
$(package)_sha256_hash=c9cb278d3b28dcc36b8d09e8cad51c0eca754eb004cb0247d4703cb4472b58b4

define $(package)_set_vars
$(package)_config_opts=--disable-shared --without-tools --without-tests --disable-sdltest
$(package)_config_opts += --disable-gprof --disable-gcov --disable-mudflap
$(package)_config_opts_linux=--with-pic
endef

define $(package)_preprocess_cmds
  cp -f $(BASEDIR)/config.guess $(BASEDIR)/config.sub use
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

define $(package)_postprocess_cmds
  rm lib/*.la
endef
