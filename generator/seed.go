package generator

import (
	"crypto/rand"
	"encoding/binary"
)

func GenerateSeed() Seed {
	var seed Seed

	for {

		bytes := make([]byte, 4)
		_, e := rand.Read(bytes)
		if e != nil {
			panic(e)
		}

		seed.SizeDictionary = binary.BigEndian.Uint16(bytes[:2])
		if seed.SizeDictionary < 32 {
			seed.SizeDictionary = binary.LittleEndian.Uint16(bytes[:2])
			if seed.SizeDictionary < 32 {
				continue
			}
		}

		seed.SizePassword = uint16(bytes[2]) + 8
		seed.CountAttempts = uint8(bytes[3])%10 + 1

		break
	}

	return seed
}

func ParseSeed(digit uint64) Seed {
	var seed Seed

	seed.SizeDictionary = uint16(digit % 65536)
	seed.SizePassword = uint16(digit>>16%256 + 8)
	seed.CountAttempts = uint8(digit >> 24 % 16)

	return seed
}

func ParseOrGenerateSeed(digit uint64) Seed {
	if digit == 0 {
		return GenerateSeed()
	}
	return ParseSeed(digit)
}

type Seed struct {
	SizeDictionary uint16 // 16 bits
	SizePassword   uint16 // if -= 8 then 8 bits
	CountAttempts  uint8  // 5 bits
}

func (seed *Seed) ToUint64() uint64 {
	// | Reserved | NumberAttempts | SizePasswd | SizeDictionary |
	// | 36 bits  |     4 bits     |   8 bits   |     16 bits    |
	var result uint64

	result += uint64(seed.SizeDictionary)
	result += (uint64(seed.SizePassword) - 8) << 16
	result += uint64(seed.CountAttempts) << 24

	return result
}
