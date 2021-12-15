function make_canvas(w, h) {
	let c = document.createElement('canvas')
	c.width = w
	c.height = h
	let c2d = c.getContext('2d')
}

WebAssembly.instantiate(WASM_CODE, {
	env: {}
}).then(result => {
	let ex = result.instance.exports
	window.ex = ex
	
	let w=416
	let h=316
	let menu_w = 400
	let menu_h = 156
	
	let data = new Uint8ClampedArray(ex.memory.buffer, ex.grp.value, w*h*4)
	let image = new ImageData(data, w, h)
	
	let data2 = new Uint8ClampedArray(ex.memory.buffer, ex.Menu_grp.value, menu_w*menu_h*4)
	let image2 = new ImageData(data2, menu_w, menu_h)
	
	let c2d = $canvas.getContext('2d')
	
	ex.__wasm_call_ctors()
	ex.Sim_reset(false)
	
	ex.Dot_create(50, 50, 2)
	
	function update() {
		ex.Platform_frame()
		for (var i=0; i<w*h; i++) {
			data[i*4+3] = 255;
		}
		for (var i=0; i<data2.length; i+=4)
			data2[i+3] = 255;
		c2d.putImageData(image, -8, -8)
		c2d.putImageData(image2, 0, 300)
		window.requestAnimationFrame(update)
	}
	update()
	
	/*result.instance.exports.memory.grow(100)
	let b = result.instance.exports.memory.buffer
	let w = $canvas.width
	let h = $canvas.height
	let data = new Uint8ClampedArray(b, ex.frame_buffer, w*h*4)
	let image = new ImageData(data, w, h)
	let ctx = $canvas.getContext('2d')
	
	function update() {
		result.instance.exports.life(w, h, ex.__heap_base)
		ctx.putImageData(image, 0, 0)
		window.requestAnimationFrame(update)
	}
	window.requestAnimationFrame(update)
/*	$canvas.onmousemove = function(e) {
		let x = e.offsetX | 0
		let y = e.offsetY | 0
		console.log(x,y)
		data[(y*w+x)*4+3] = 255
	}*/
})
