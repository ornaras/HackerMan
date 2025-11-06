package l10n

var DefaultLocale = English

type Locale struct {
	SeedStartArgDescription string

	InputPasswordMessage string
	WrongPasswordMessage string
	WinMessage           string
	LoseMessage          string
	CurrentSeedMessage   string
	CountAttemptsMessage string
}
