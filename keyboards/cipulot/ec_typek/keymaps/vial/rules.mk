VIA_ENABLE = yes
VIAL_ENABLE = yes

TRI_LAYER_ENABLE    = yes
MAGIC_ENABLE 		= yes
BOOTMAGIC_ENABLE    = yes
CONSOLE_ENABLE      = yes
TAP_DANCE_ENABLE    = yes
CAPS_WORD_ENABLE    = yes

SRC += key_overload.c
SRC += via_menu.c

# ####################
# ### Space Saving ###
# ####################
LTO_ENABLE 			= yes
SPACE_CADET_ENABLE  = no
GRAVE_ESC_ENABLE 	= no 
MUSIC_ENABLE 		= no
