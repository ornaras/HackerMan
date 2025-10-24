//go:build linux || darwin || unix
// +build linux darwin unix

package l10n

import (
	"io"
	"os"
	"strings"
)

func GetCurrentLocale() Locale {
	var code string = getLocaleFromEnv()
	if code == "" {
		code = getLocaleFromFile()
	}

	if code != "" {
		short := strings.Split(code, "_")[0]
		switch short {
		case "ru":
			return Russian
		case "en":
			return English
		}
	}

	return DefaultLocale
}

func getLocaleFromEnv() string {
	const keys = "LANG;LANGUAGE;LC_ALL"

	for _, key := range strings.Split(keys, ";") {
		value, success := os.LookupEnv(key)
		if success {
			return value
		}
	}

	return ""
}

func getLocaleFromFile() string {
	const filePaths = "/etc/locale.conf;/etc/default/locale"
	const keys = "LANG;LANGUAGE;LC_ALL"

	for _, filepath := range strings.Split(filePaths, ";") {
		f, e := os.OpenFile(filepath, os.O_RDONLY, 0)
		if e != nil {
			continue
		}
		b, e := io.ReadAll(f)
		if e != nil {
			continue
		}
		lines := strings.Split(string(b), "\n")
		for _, line := range lines {
			items := strings.Split(line, "=")
			if strings.Contains(keys, items[0]) {
				e = f.Close()
				return strings.Trim(items[1], "\"")
			}
		}
		e = f.Close()
	}

	return ""
}
