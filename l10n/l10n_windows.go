//go:build windows

package l10n

import (
	"strings"
	"unsafe"

	"golang.org/x/sys/windows"
)

var (
	kernel32      = windows.NewLazySystemDLL("kernel32.dll")
	getUserLocale = kernel32.NewProc("GetUserDefaultLocaleName")
)

func GetCurrentLocale() Locale {
	const LocaleNameMaxLength = 85
	buf := make([]uint16, LocaleNameMaxLength)

	ret, _, _ := getUserLocale.Call(
		uintptr(unsafe.Pointer(&buf[0])),
		uintptr(LocaleNameMaxLength),
	)

	if ret != 0 {
		short := strings.Split(windows.UTF16ToString(buf), "-")[0]
		switch short {
		case "ru":
			return Russian
		case "en":
			return English
		}
	}

	return DefaultLocale
}
