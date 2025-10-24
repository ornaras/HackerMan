package generator

import "testing"

func TestConvertWithGenerate(t *testing.T) {
	for i := 0; i < 10000; i++ {
		seed := GenerateSeed()
		digit := seed.ToUint64()
		newSeed := ParseSeed(digit)
		if seed != newSeed {
			t.Fatal("parsed seed does not match generated seed")
		}
	}
}
