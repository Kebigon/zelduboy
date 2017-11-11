
all: items_8x16.png player_16x16.png playerSword_16x16.png animationSword_16x16.png tileset_16x16.png

clean:
	rm -f items_8x16.png player_16x16.png playerSword_16x16.png animationSword_16x16.png tileset_16x16.png

items_8x16.png:
	convert -append sprites/items/item_*.png -threshold 25% items_8x16.png
	optipng -o7 -strip all -quiet items_8x16.png

player_16x16.png:
	convert -append sprites/player/player-*.png -threshold 25% player_16x16.png
	optipng -o7 -strip all -quiet player_16x16.png

playerSword_16x16.png:
	convert -append sprites/player/playerSword-*.png -threshold 25% playerSword_16x16.png
	optipng -o7 -strip all -quiet playerSword_16x16.png

animationSword_16x16.png:
	convert -append sprites/animations/sword-*.png -threshold 25% animationSword_16x16.png
	optipng -o7 -strip all -quiet animationSword_16x16.png

tileset_16x16.png:
	convert -append tiles/tile-*.png -threshold 25% tileset_16x16.png
	optipng -o7 -strip all -quiet tileset_16x16.png
