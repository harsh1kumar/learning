#!/usr/bin/env python3

import os, platform, logging

if platform.platform().startswith('Windows'):
	logfilepath = os.path.join(os.getenv('HOMEDRIVE'), os.getenv('HOMEPATH'), 'my_py.log')
else:
	logfilepath = os.path.join(os.getenv('HOME'), 'my_py.log')

print('Logs will be saved in:', logfilepath)

logging.basicConfig(
	filename = logfilepath,
	filemode = 'w',
	format = '%(asctime)s : %(levelname)s : %(message)s',
	level = logging.DEBUG
)

logging.debug('Start of the program')
logging.info('Doing Something')
logging.warning('Dying Now')

