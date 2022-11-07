# Silver Runner

## Another runner like program

This is a Project that I developed in my first year at Epitech.
It was the first time I created a game.
I put in a lot of effort to try and make the game as pleasing a possible while remaining in a (about) 3 week deadline.

## 3 weeks to create a Video Game

October 2021, 30th: The project begins
On the 30th of october, the github repository `B-MUL-100-PAR-1-2-myrunner-h****.l********` see's the light for the first time.

* **October 2021, 30th - December 2021, 7th**:
Researching assets for the video game.
Thinking of the structure of the visual environement to create.
While juggling with two other Epitech projects.

* **December 2021, 7th**: initial commits

* **December 2021, 10th**: Focusing solely on the game and leaving the two other projects to go to waste.

* **December 2021, 7th - December 2021, 31st**:
First chunk of the code is uploaded, at the time, there is only a paralax that is in place.

* **January 2022, 1st**: The sprites make their appearance in the game and the game becomes a laggy game but a game.

* **January 2022, 3rd**: Slowly fixing game lags and starting to manage three other Epitech projects.

* **January 2022, 4th**: Fixing more lags and Added the keyboard help section (option -k when running the binary).

* **January 2022, 5th**: Added the end screens.

* **January 2022, 6**: Attempting to fix the collistions between assets.

* **January 2022, 7th**: Attempting to fix memory allocations in the text (ex: score)

* **January 2022, 9th**: Correcting as many coding style issues as I could.

## Thanks for the log, but how do I run the game?

In order to run the game, you will need:

### Dependencies

* To be in a linux environement (a linux in a virtual environement will do)
* Have basic knowledge of how the linux bash works.
* Have the following packages installed:
  * `make` (it is normally installed by default [to make sure, type `make --version`, if the response is not `bash: make: command not found` this means `make` is installed on your system])
  * `gcc` ([https://www.ubuntupit.com/how-to-install-and-use-gcc-compiler-on-linux-system/](https://www.ubuntupit.com/how-to-install-and-use-gcc-compiler-on-linux-system/) to install `gcc` if it is not installed.)
  * `CSFML-devel` ([https://github.com/Hanra-s-work/install_csfml](https://github.com/Hanra-s-work/install_csfml))
* Cloned this repository onto your computer.

### Compiling

Next step : compiling !
This game has been programmed in c.
Because C is not a language that is an on the run type (call the file containing the code as if it was an executable) there is an additional step that is required before viewing the result.

For this project, if you have successfully installed the required dependencies:

* open a terminal in or navigate to the folder named files of this repository
* type the word `make re` in your terminal and press the [ENTER] key to run the command (this will call a file named `Makefile` which is in charge of compiling a program (in our context))

### Running the game

If the compilation was successefull (a bunch of lines being displayed on the screen which should finish with `gcc -g my_runner.c option_dealing.c how_to_play.c show_credits.c title.c next_frame_full.c init_backgrounds.c init_background_overflow.c init_time.c init_window.c -o my_runner -lcsfml-graphics -lcsfml-system -lcsfml-audio -L lib/audio -lmyaudio -L lib/my/ -lmy -L lib/sprite -lmysprite -L lib/mouse -lmymouse -L lib/window -lmywindow -L lib/event -lmyevents -L lib/silvers -lmysilvers -L lib/text -lmytext -L lib/end -lmyend -L lib/convert -lmyconvert -L lib/game_assets -lmyassets -L lib/scores -lmyscores -L lib/image -lmyimage -L lib/level -lmylevel -g3` line) you can type the command `ls` which should list the files in the current directory.

In the displayed files you should be able to see text (generally in green) containing the words `my_runner` (not `my_runner.c` or `my_runner.o` these are just files, they are not an executable).

If you can see `my_runner`, then you are good to go.
To run the binary, type:

* `./my_runner` (then press the [ENTER] key) in your terminal to display the basic options.
* `./my_runner -h` (then press the [ENTER] key) in your terminal to display the help section
* `./my_runner -l` (then press the [ENTER] key) in your terminal to start the game.
* `./my_runner -k` (then press the [ENTER] key) in your terminal to display the keys that can be used to interact with the game.
* `./my_runner -c` (then press the [ENTER] key) in your terminal to display the credit section.

Happy Gaming !!

## Hardware support

The current known hardware (up to this date [7/11/2022]) capable of compiling/running the game is a linux distribution.
All other known systems currently fail to compile libraries (ex: Windows) or install CSFML-devel (ex: Macs with the Silicon chips).

## License

This license applies for the code of this game, however, the licensing for the assets may differ depending on the asset.

### Where to find the links to the assets

The links for the assets can be found in the `files/html` folder, the `files/temp/html`

### Font authors

The fonts belong to SEGA (`NiseSegaSonic.ttf`) and Microsoft (`Helvetica-Bold.ttf`) and their licensing is applied.

### Where are the credits

Crediting for the assets used can be found in the `./runner -c` option of the program as well as in the `show_credits.c`

### Ownership

I do not intend to sell this game, thus all assets used belong to their respective owners.

### A Problem? Contact me

If the owner of an asset has a problem with any of the assets used. Do not hesitate to contact me on my github page: [@HenraL](https://github.com/HenraL)

### Aim of the game

This game is for educational and recreational purposes and is licenced under the following terms:

### License of the code

[![Creative Commons Licence](https://i.creativecommons.org/l/by-sa/4.0/88x31.png)](http://creativecommons.org/licenses/by-sa/4.0/)

<span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">Silver Runner</span> by [Henry Letellier](https://github.com/HenraL/) is licensed under a [Creative Commons Attribution-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-sa/4.0/).
Based on a work at [https://github.com/HenraL/probable-octo-enigma-my_runner](https://github.com/HenraL/probable-octo-enigma-my_runner)

An html version of this licensing can be found [here](./license.html) (license.html).
