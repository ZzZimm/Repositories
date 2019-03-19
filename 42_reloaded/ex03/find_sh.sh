find . -name '*.sh' -type f -print | rev | cut -c 4- |  cut -d / -f 1 | rev
