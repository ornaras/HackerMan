package generator

import (
	"math/rand"
)

func GenerateDictionary(seed Seed) (dict string) {
	const AvailableSymbols = "qwertyuiopasdfghjklzxcvbmQWERTYUIOPASDFGHJKLZXCVBNM1234567890!@#$%^&*"
	var CountAvailableSymbols = len(AvailableSymbols)

	var i uint16
	for i = 0; i < seed.SizeDictionary; i++ {
		index := rand.Intn(CountAvailableSymbols)
		dict += string(AvailableSymbols[index])
	}

	return
}

func GeneratePassword(seed Seed, dict string) (password string) {
	var i uint16
	for i = 0; i < seed.SizePassword; i++ {
		index := rand.Intn(int(seed.SizeDictionary))
		password += string(dict[index])
	}

	return
}
