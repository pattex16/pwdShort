# pwdShorten
My directory shortener for bash and zsh $PS1 prompts inspired by [jonathonball's](https://github.com/jonathonball/pwd-shorten)

## Requirements
- gcc, or any compiler really

## Usage
- gcc main.c -o pwdShorten
- pwdShorten $PWD $HOME

### bash
1. Make `pwd-shorten` available in your `$PATH`.
2. Add `$(pwd-shorten)` to your `$PS1` prompt.

### zsh
1. Make `pwd-shorten` available in your `$PATH`.
2. Add `$(pwd-shorten)` to your `*.zsh-theme` file.

## Example Output
The directory path in your prompt will be shortened:

    /very-long-directory-name/another-long-one/tacos.txt

becomes

    /ver+/ano+/tacos.txt

Home directories will be changed out as well:

    /home/jonball/example/directory

becomes

    ~/exa+/directory

## Configuration
You can override these defaults by creating a config file in `~/.config/pwd-shorten` called `config.ini` containing a top-level section titled `[settings]`.

### Config Values
The following values can be set in your config

#### `break_length`
Length at which a directory name will be shortened
- default: `5`

#### `keep_length`
How much of the original directory name to keep
- default `3`

#### `replacement`
Symbol used to indicate that a directory name has been shortened.
- default `+`

### Example Configuration

    [settings]
    break_length = 5
    keep_length  = 3
    replacement  = +
