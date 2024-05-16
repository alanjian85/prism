mod config;

use clap::Parser;
use config::Config;
use image::{Rgb, RgbImage};

fn main() {
    let config = Config::parse();
    let width = config.size.width;
    let height = config.size.height;

    let mut img = RgbImage::new(width, height);
    for y in 0..height {
        for x in 0..width {
            let r = x as f32 / (width - 1) as f32;
            let g = y as f32 / (height - 1) as f32;
            let b = 0.25;

            let r = (r * 255.) as u8;
            let g = (g * 255.) as u8;
            let b = (b * 255.) as u8;

            img.put_pixel(x, y, Rgb([r, g, b]));
        }
    }
    img.save(config.output).unwrap();
}
