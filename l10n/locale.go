package l10n

var DefaultLocale = English

type Locale struct {
	CurrentSeedText string

	SeedStartArgDescription string

	InputPasswordMessage string
	WrongPasswordMessage string
	WinMessage           string
	LoseMessage          string
}
