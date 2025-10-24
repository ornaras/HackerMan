package generator

import (
	"strings"
	"testing"
)

func TestGenerators(t *testing.T) {
	seed := Seed{
		SizeDictionary: 512,
		SizePassword:   10,
	}
	for i := 0; i <= 10000; i++ {
		dict := GenerateDictionary(seed)
		if len(dict) != int(seed.SizeDictionary) {
			t.Fatalf("Dictionary length does not match seed (Current lenght: %d, Need: %d)", len(dict), seed.SizeDictionary)
		}

		pswd := GeneratePassword(seed, dict)
		if len(pswd) != int(seed.SizePassword) {
			t.Fatalf("Password length does not match seed (Current lenght: %d, Need: %d)", len(pswd), seed.SizePassword)
		}

		for _, symbol := range pswd {
			if !strings.Contains(dict, string(symbol)) {
				t.Fatalf("Symbol not found in dictionary (Symbol: %s, Dictionary: %s)", string(symbol), dict)
			}
		}
	}
}
