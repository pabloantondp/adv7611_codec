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
#include <linux/device.h>
#include <media/adv7604.h>

#include "adv7611_codec.h"


struct adv7611_sound_priv {

};

static int adv7611_ops_hw_params(struct snd_pcm_substream * substream,
		struct snd_pcm_hw_params * hw_params, struct snd_soc_dai * dai){

	dev_info(dai->dev, "ADV7611 Audio Codec Ops hw params\n");

	return 0;
}

static int adv7611_ops_startup(struct snd_pcm_substream *substream,
		struct snd_soc_dai * dai){
	dev_info(dai->dev, "ADV7611 Audio Codec Ops startup\n");

	return 0;
}

static void adv7611_ops_shutdown(struct snd_pcm_substream * substream,
		struct snd_soc_dai * dai){

	dev_info(dai->dev, "ADV7611 Audio Codec Ops shutdown\n");
}

static int adv7611_codec_probe(struct snd_soc_codec * codec){

	dev_info(codec->dev, "ADV7611 Audio Codec Driver probe\n");

	return 0;
}

static struct snd_soc_codec_driver adv7611_audio_codec = {
	/* We can define here */
	.probe				= adv7611_codec_probe,

	/*
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
*/
	// ALSA PCM audio operations
	.startup		= adv7611_ops_startup,
	.shutdown		= adv7611_ops_shutdown,
	.hw_params		= adv7611_ops_hw_params,
	//.hw_free		= ,
	//.prepare		= ,

};

#define SGTL5000_FORMATS (SNDRV_PCM_FMTBIT_S16_LE |\
			SNDRV_PCM_FMTBIT_S20_3LE |\
			SNDRV_PCM_FMTBIT_S24_LE |\
			SNDRV_PCM_FMTBIT_S32_LE)

// DAI (Digital Audio Interface) struct for the codec
static struct snd_soc_dai_driver adv7611_dai = {
	.name 	= "snd_soc_adv7611",
	.capture = {
			.stream_name = "HDMI-Capture",
			.channels_min = 1,
			.channels_max = 2,
			.rates = SNDRV_PCM_RATE_8000_48000 | SNDRV_PCM_RATE_96000,
			.formats = SGTL5000_FORMATS,
		},
	.ops 	= &adv7611_dai_ops, // Operations
};


/*
 *
 */
static int adv7611_codec_dev_probe(struct platform_device *pdev)
{
	struct adv7611_sound_priv *adv7611;
	int ret;

	// Check good value
	if (pdev == NULL )
		return -ENODEV;

	// Register the codec
	ret = snd_soc_register_codec(&pdev->dev,
			&adv7611_audio_codec,
			&adv7611_dai,
			1);

	if (ret)
		return -ENODEV;

	dev_info(&pdev->dev, "%s register\n", pdev->name);

	return ret;
}


static int adv7611_codec_dev_remove(struct platform_device *pdev)
{
	snd_soc_unregister_codec(&pdev->dev);
	return 0;
}

static struct platform_driver adv7611_driver = {
	.driver	= {
		.name	= DRV_CODEC_NAME,
		.owner	= THIS_MODULE,
	},
	.probe 	= adv7611_codec_dev_probe,
	.remove	= adv7611_codec_dev_remove,
};

module_platform_driver(adv7611_driver);

MODULE_AUTHOR("Pablo Anton <pablo.antond@vodalys-labs.com>");
MODULE_AUTHOR("Jean-Michel Hautbois <jean-michel.hautbois@vodalys.com>");
MODULE_DESCRIPTION("ADV7611 Audio Codec Driver");
MODULE_LICENSE("GPL");
