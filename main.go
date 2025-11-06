package main

import (
	"HackerMan/generator"
	"HackerMan/l10n"
	"flag"
	"fmt"
	"os"
	"os/user"
)

var (
	numbSeed uint64
	seed     generator.Seed
	dict     string
	passwd   string
	locale   l10n.Locale
)

func init() {
	locale = l10n.GetCurrentLocale()

	flag.Uint64Var(&numbSeed, "seed", 0, locale.SeedStartArgDescription)
}

func main() {
	flag.Parse()

	seed = generator.ParseOrGenerateSeed(numbSeed)
	fmt.Println(locale.CurrentSeedText, ":", seed.ToUint64())
	dict = generator.GenerateDictionary(seed)
	passwd = generator.GeneratePassword(seed, dict)

	var currAttempt uint8 = 1
	for ; currAttempt <= seed.CountAttempts; currAttempt++ {
		fmt.Print(locale.InputPasswordMessage)
		var currInput string
		for {
			_, _ = fmt.Fscanln(os.Stdin, &currInput)
			if currInput != "" {
				break
			}
		}
		if currInput == passwd {
			u, err := user.Current()
			var userName = "Anonimous"
			if err == nil {
				userName = u.Username
			}
			fmt.Printf(locale.WinMessage, userName)
			break
		} else if currAttempt == seed.CountAttempts {
			u, err := user.Current()
			var userName = "Anonimous"
			if err == nil {
				userName = u.Username
			}
			fmt.Printf(locale.LoseMessage, userName)
			break
		}
		fmt.Printf(locale.WrongPasswordMessage, seed.CountAttempts-currAttempt, seed.CountAttempts)
		fmt.Println()
	}
}
