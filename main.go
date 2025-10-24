package main

import (
	"HackerMan/generator"
	"flag"
	"fmt"
)

var (
	numbSeed uint64
	seed     generator.Seed
)

func init() {
	flag.Uint64Var(&numbSeed, "seed", 0, "number of seeds to generate")
}

func main() {
	flag.Parse()
	seed = generator.ParseOrGenerateSeed(numbSeed)
	fmt.Println("Current seed is: ", seed.ToUint64())
}
