mod config;
mod ray;

use clap::Parser;
use config::Config;
use image::{Rgb, RgbImage};
use nalgebra::point;
use ray::Ray;

fn main() {
    let config = Config::parse();
    let width = config.size.width;
    let height = config.size.height;

    let mut img = RgbImage::new(width, height);
    for y in 0..height {
        for x in 0..width {
            let o = point![0., 0., 0.];
            let p = point![
                x as f64 / (width - 1) as f64 * 2. - 1.,
                y as f64 / (height - 1) as f64 * 2. - 1.,
            ];
            let ray = Ray::new(o, point![p.x, p.y, 0.] - o);

            let r = ((ray.d.x + 1.) / 2. * 255.) as u8;
            let g = ((ray.d.y + 1.) / 2. * 255.) as u8;
            let b = 0x40;

            img.put_pixel(x, y, Rgb([r, g, b]));
        }
    }
    img.save(config.output).unwrap();
}
