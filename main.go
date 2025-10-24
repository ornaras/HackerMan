package main

import (
	"HackerMan/generator"
	"HackerMan/l10n"
	"flag"
	"fmt"
)

var (
	numbSeed uint64
	seed     generator.Seed
	dict     string
	passwd   string
	locale   l10n.Locale
)

func init() {
	flag.Uint64Var(&numbSeed, "seed", 0, locale.SeedStartArgDescription)
}

func main() {
	flag.Parse()

	seed = generator.ParseOrGenerateSeed(numbSeed)
	fmt.Println(locale.CurrentSeedText, ":", seed.ToUint64())
	dict = generator.GenerateDictionary(seed)
	passwd = generator.GeneratePassword(seed, dict)
}
