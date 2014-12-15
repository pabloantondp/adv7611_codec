/*
 /*
 * Copyright (C) 2014 Vodalys
 * Author: Pablo Anton <pabloantondp@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <sound/soc.h>

struct adv7611_priv {
	struct snd_soc_codec	*codec;
	struct i2c_client		*i2c;
	struct regmap			*regmap;
};

static struct snd_soc_codec_driver adv7611_codec = {
	/* We can define here
	.probe				= ,
	.remove				= ,
	.suspend			= ,
	.resume				= ,
	.component_driver	= , // struct snd_soc_component_driver

	// Default control and setup, added after probe() is run
	.controls			= , // snd_kcontrol_new
	.num_controls		= , // int
 	.dapm_widgets		= , // snd_soc_dapm_widget
	.num_dapm_widgets	= , // int
	.dapm_routes		= , // snd_soc_dapm_route
	.num_dapm_routes	= , // int

	// codec wide operations
	.set_sysclk			= ,
	.set_pll			= ,

	// codec IO
	.get_regmap			= ,
	.read				= ,
	.write				= ,
	.reg_cache_size		= , // unsigned int
	.reg_cache_step		= , // short
	.reg_word_size		= , // short
	.reg_cache_default	= ,

	// codec bias level
	.set_bias_level		= ,
	.idle_bias_off		= , // bool
	.suspend_bias_off 	= , // bool

	.seq_notifier		= ,
	 */
};

static struct snd_soc_dai_ops adv7611_dai_ops = {
	/* We can define here DAI clocking configuration
	.set_sysclk		= ,
	.set_pll		= ,
	.set_clkdiv		= ,
	.set_bclk_ratio	= ,

	 //DAI format configuration
	.set_fmt				= ,
	.xlate_tdm_slot_mask	= ,
	.set_tdm_slot			= ,
	.set_channel_map		= ,
	.set_tristate			= ,

	// Digital Mute
	.digital_mute	= ,
	.mute_stream	= ,

	// ALSA PCM audio operations
	.startup		= ,
	.shutdown		= ,
	.hw_params		= ,
	.hw_free		= ,
	.prepare		= ,
	*/
};

static struct snd_soc_dai_driver adv7611_dai = {
	.name 	= "adv7611_codec",
	.ops 	= &adv7611_dai_ops,
};


/*
 *
 */
static int avd7611_codec_probe(struct platform_device *pdev)
{
	int ret;
	struct adv7611_priv *adv7611;

	// Reserve memory for adv7611_priv struct
	adv7611 = devm_kzalloc(&pdev->dev, sizeof(struct adv7611_priv),
				      GFP_KERNEL);

	// Check error
	if (adv7611 == NULL)
		return -ENOMEM;

	// TODO take client I2C
	//adv7611->i2c = pdev->client;

	// TODO take regmap
	//adv7611->regmap = pdev->regmap;

	platform_set_drvdata(pdev, adv7611);

	ret = snd_soc_register_codec(&pdev->dev, &adv7611_codec,
				adv7611_dai, ARRAY_SIZE(adv7611_dai));
		if (ret) {
			dev_err(&pdev->dev, "Failed to register codec\n");
			return -EINVAL;
		}
		return ret;
	return 0;
}


static int avd7611_codec_remove(struct platform_device *pdev)
{
	return 0;
}

static struct platform_driver avd7611_driver = {
	.driver	= {
		.name	= "avd7611",
		.owner	= THIS_MODULE,
	},
	.probe 	= avd7611_codec_probe,
	.remove	= avd7611_codec_remove,
};

module_platform_driver(avd7611_driver);

MODULE_AUTHOR("Pablo Anton <pablo.anton@vodalys-labs.com>);
MODULE_DESCRIPTION("ADV7611 HDMI Audio Codec");
MODULE_LICENSE("GPL");
