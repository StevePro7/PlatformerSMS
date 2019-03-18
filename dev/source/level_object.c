#include "level_object.h"

#include "..\banks\bank4.h"
#include "..\banks\bank5.h"

const unsigned char *world01data[] =
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
};
const unsigned char *world02data[] =
{
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
};
const unsigned char *world03data[] =
{
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
};
const unsigned char *world04data[] =
{
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

const unsigned char world01size[] =
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
};
const unsigned char world02size[] =
{
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
};
const unsigned char world03size[] =
{
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
};
const unsigned char world04size[] =
{
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

const unsigned char world01bank[] =
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
};
const unsigned char world02bank[] =
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
};
const unsigned char world03bank[] =
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
};
const unsigned char world04bank[] =
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
};

/*
const unsigned char *leveldata[] =
{
	level0201_txt,
	level0202_txt,
	level0203_txt,
	level0301_txt,
	level0401_txt,
	level0402_txt,
	level0501_txt,
	level0502_txt,
	level0503_txt,
	level0504_txt,
};

const unsigned char levelsize[] =
{
	level0201_txt_size,
	level0202_txt_size,
	level0203_txt_size,
	level0301_txt_size,
	level0401_txt_size,
	level0402_txt_size,
	level0501_txt_size,
	level0502_txt_size,
	level0503_txt_size,
	level0504_txt_size,
};

const unsigned char levelbank[] =
{
	level0201_txt_bank,
	level0202_txt_bank,
	level0203_txt_bank,
	level0301_txt_bank,
	level0401_txt_bank,
	level0402_txt_bank,
	level0501_txt_bank,
	level0502_txt_bank,
	level0503_txt_bank,
	level0504_txt_bank,
}*/