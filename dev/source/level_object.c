#include "level_object.h"

#include "..\banks\bank3.h"
#include "..\banks\bank4.h"
#include "..\banks\bank5.h"

const unsigned char *tutorialdata[] =
{
	tutorial0_txt,
	tutorial1_txt,
	tutorial2_txt,
	tutorial3_txt,
	tutorial4_txt,
	tutorial5_txt,
	tutorial6_txt,
	tutorial7_txt,
	tutorial8_txt,
	tutorial9_txt,
};

const unsigned char tutorialsize[] =
{
	tutorial0_txt_bank,
	tutorial1_txt_bank,
	tutorial2_txt_bank,
	tutorial3_txt_bank,
	tutorial4_txt_bank,
	tutorial5_txt_bank,
	tutorial6_txt_bank,
	tutorial7_txt_bank,
	tutorial8_txt_bank,
	tutorial9_txt_bank,
};

const unsigned char tutorialbank[] =
{
	tutorial0_txt_size,
	tutorial1_txt_size,
	tutorial2_txt_size,
	tutorial3_txt_size,
	tutorial4_txt_size,
	tutorial5_txt_size,
	tutorial6_txt_size,
	tutorial7_txt_size,
	tutorial8_txt_size,
	tutorial9_txt_size,
};


const unsigned char *levelAAdata[] =
{
	level0101_txt,
	level0102_txt,
	level0103_txt,
	level0104_txt,
	level0105_txt,
	level0106_txt,
	level0107_txt,
	level0108_txt,
	level0109_txt,
	level0110_txt,
	level0201_txt,
	level0202_txt,
	level0203_txt,
	level0204_txt,
	level0205_txt,
	level0206_txt,
	level0207_txt,
	level0208_txt,
	level0209_txt,
	level0210_txt,
	level0301_txt,
	level0302_txt,
	level0303_txt,
	level0304_txt,
	level0305_txt,
	level0306_txt,
	level0307_txt,
	level0308_txt,
	level0309_txt,
	level0310_txt,
	level0401_txt,
	level0402_txt,
	level0403_txt,
	level0404_txt,
	level0405_txt,
	level0406_txt,
	level0407_txt,
	level0408_txt,
	level0409_txt,
	level0410_txt,
};

const unsigned char levelAAsize[] =
{
	level0101_txt_size,
	level0102_txt_size,
	level0103_txt_size,
	level0104_txt_size,
	level0105_txt_size,
	level0106_txt_size,
	level0107_txt_size,
	level0108_txt_size,
	level0109_txt_size,
	level0110_txt_size,
	level0201_txt_size,
	level0202_txt_size,
	level0203_txt_size,
	level0204_txt_size,
	level0205_txt_size,
	level0206_txt_size,
	level0207_txt_size,
	level0208_txt_size,
	level0209_txt_size,
	level0210_txt_size,
	level0301_txt_size,
	level0302_txt_size,
	level0303_txt_size,
	level0304_txt_size,
	level0305_txt_size,
	level0306_txt_size,
	level0307_txt_size,
	level0308_txt_size,
	level0309_txt_size,
	level0310_txt_size,
	level0401_txt_size,
	level0402_txt_size,
	level0403_txt_size,
	level0404_txt_size,
	level0405_txt_size,
	level0406_txt_size,
	level0407_txt_size,
	level0408_txt_size,
	level0409_txt_size,
	level0410_txt_size,
};

const unsigned char levelAAbank[] =
{
	level0101_txt_bank,
	level0102_txt_bank,
	level0103_txt_bank,
	level0104_txt_bank,
	level0105_txt_bank,
	level0106_txt_bank,
	level0107_txt_bank,
	level0108_txt_bank,
	level0109_txt_bank,
	level0110_txt_bank,
	level0201_txt_bank,
	level0202_txt_bank,
	level0203_txt_bank,
	level0204_txt_bank,
	level0205_txt_bank,
	level0206_txt_bank,
	level0207_txt_bank,
	level0208_txt_bank,
	level0209_txt_bank,
	level0210_txt_bank,
	level0301_txt_bank,
	level0302_txt_bank,
	level0303_txt_bank,
	level0304_txt_bank,
	level0305_txt_bank,
	level0306_txt_bank,
	level0307_txt_bank,
	level0308_txt_bank,
	level0309_txt_bank,
	level0310_txt_bank,
	level0401_txt_bank,
	level0402_txt_bank,
	level0403_txt_bank,
	level0404_txt_bank,
	level0405_txt_bank,
	level0406_txt_bank,
	level0407_txt_bank,
	level0408_txt_bank,
	level0409_txt_bank,
	level0410_txt_bank,
};


const unsigned char *levelBBdata[] =
{
	level0501_txt,
	level0502_txt,
	level0503_txt,
	level0504_txt,
	level0505_txt,
	level0506_txt,
	level0507_txt,
	level0508_txt,
	level0509_txt,
	level0510_txt,
	level0601_txt,
	level0602_txt,
	level0603_txt,
	level0604_txt,
	level0605_txt,
	level0606_txt,
	level0607_txt,
	level0608_txt,
	level0609_txt,
	level0610_txt,
	level0701_txt,
	level0702_txt,
	level0703_txt,
	level0704_txt,
	level0705_txt,
	level0706_txt,
	level0707_txt,
	level0708_txt,
	level0709_txt,
	level0710_txt,
	level0801_txt,
	level0802_txt,
	level0803_txt,
	level0804_txt,
	level0805_txt,
	level0806_txt,
	level0807_txt,
	level0808_txt,
	level0809_txt,
	level0810_txt,
};

const unsigned char levelBBsize[] =
{
	level0501_txt_size,
	level0502_txt_size,
	level0503_txt_size,
	level0504_txt_size,
	level0505_txt_size,
	level0506_txt_size,
	level0507_txt_size,
	level0508_txt_size,
	level0509_txt_size,
	level0510_txt_size,
	level0601_txt_size,
	level0602_txt_size,
	level0603_txt_size,
	level0604_txt_size,
	level0605_txt_size,
	level0606_txt_size,
	level0607_txt_size,
	level0608_txt_size,
	level0609_txt_size,
	level0610_txt_size,
	level0701_txt_size,
	level0702_txt_size,
	level0703_txt_size,
	level0704_txt_size,
	level0705_txt_size,
	level0706_txt_size,
	level0707_txt_size,
	level0708_txt_size,
	level0709_txt_size,
	level0710_txt_size,
	level0801_txt_size,
	level0802_txt_size,
	level0803_txt_size,
	level0804_txt_size,
	level0805_txt_size,
	level0806_txt_size,
	level0807_txt_size,
	level0808_txt_size,
	level0809_txt_size,
	level0810_txt_size,
};

const unsigned char levelBBbank[] =
{
	level0501_txt_bank,
	level0502_txt_bank,
	level0503_txt_bank,
	level0504_txt_bank,
	level0505_txt_bank,
	level0506_txt_bank,
	level0507_txt_bank,
	level0508_txt_bank,
	level0509_txt_bank,
	level0510_txt_bank,
	level0601_txt_bank,
	level0602_txt_bank,
	level0603_txt_bank,
	level0604_txt_bank,
	level0605_txt_bank,
	level0606_txt_bank,
	level0607_txt_bank,
	level0608_txt_bank,
	level0609_txt_bank,
	level0610_txt_bank,
	level0701_txt_bank,
	level0702_txt_bank,
	level0703_txt_bank,
	level0704_txt_bank,
	level0705_txt_bank,
	level0706_txt_bank,
	level0707_txt_bank,
	level0708_txt_bank,
	level0709_txt_bank,
	level0710_txt_bank,
	level0801_txt_bank,
	level0802_txt_bank,
	level0803_txt_bank,
	level0804_txt_bank,
	level0805_txt_bank,
	level0806_txt_bank,
	level0807_txt_bank,
	level0808_txt_bank,
	level0809_txt_bank,
	level0810_txt_bank,
};
