use nalgebra::{Point3, Vector3};

pub struct Ray {
    pub o: Point3<f64>,
    pub d: Vector3<f64>,
}

impl Ray {
    pub fn new(o: Point3<f64>, d: Vector3<f64>) -> Self {
        Self { o, d }
    }
}
