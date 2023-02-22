#!/bin/bash
# SPDX-License-Identifier: GPL-2.0
# (c) 2019, Nick Desaulniers <ndesaulniers@google.com>
function check () {
  # Remove trailing commands, for example arch/arm/Makefile may add `-EL`.
  utility=$(echo ${1} | awk '{print $1;}')
  command -v "${utility}" &> /dev/null
  if [[ $? != 0 ]]; then
    echo "\$CROSS_COMPILE set to ${CROSS_COMPILE}," \
      "but unable to find ${utility}."
    exit 1
  fi
}
utilities=("${AS}" "${LD}" "${CC}" "${AR}" "${NM}" "${STRIP}" "${OBJCOPY}"
  "${OBJDUMP}")
for utility in "${utilities[@]}"; do
  check "${utility}"
done
