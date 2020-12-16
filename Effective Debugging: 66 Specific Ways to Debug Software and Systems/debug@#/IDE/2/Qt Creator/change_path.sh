#!/bin/bash

# it will always be 6 levels higher than the script location (backlash everything except '/')
YOUR_PATH=`printf '%q\n' "${PWD%/*/*/*/*/*/*}"`

# backslash each '/'
YOUR_PATH_BACKLASHES=$(sed 's;/;\\/;g' <<< "${YOUR_PATH}")

echo 'The attempted change is s/YOUR_PATH/'"${YOUR_PATH_BACKLASHES}"'/g'

sed -i 's/YOUR_PATH/'"${YOUR_PATH_BACKLASHES}"'/g' pinning-session.qws
