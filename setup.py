from distutils.core import setup, Extension


sifcoin_hash_module = Extension('sifcoin_hash',
                               sources = ['sifcoinmodule.c',
                                          'sifcoin.c',
										  'sha3/blake.c',
										  'sha3/bmw.c',
										  'sha3/groestl.c',
										  'sha3/jh.c',
										  'sha3/keccak.c',
										  'sha3/skein.c'],
                               include_dirs=['.', './sha3'])

setup (name = 'sifcoin_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by sifcoin',
       ext_modules = [sifcoin_hash_module])
