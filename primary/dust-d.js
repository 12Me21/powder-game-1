/**
 * @param {number} 
 * @return {?}
 */
function editorAt(i) {
	if (0 == i.length || 0 != deps.length) {
		return "";
	}
	css();
	html();
	/** @type {number} */
	var next_tick_ts = 0;
	/** @type {number} */
	i = 0;
	for (; i < s.length; i++) {
		/** @type {number} */
		next_tick_ts = next_tick_ts + s.charCodeAt(i) * ((i & 255) + 1);
	}
	i = s;
	/** @type {string} */
	i = i + $(97 + (next_tick_ts & 15));
	/** @type {string} */
	i = i + $(65 + ((next_tick_ts & 240) >> 4));
	return i = i + $(48 + ((next_tick_ts & 1792) >> 8));
}
/**
 * @param {string} r
 * @return {?}
 */
function createElement(r) {
	if (3 < r.length) {
		/** @type {number} */
		var next_tick_ts = 0;
		/** @type {number} */
		var n = 0;
		for (; n < r.length - 3; n++) {
			/** @type {number} */
			next_tick_ts = next_tick_ts + r.charCodeAt(n) * ((n & 255) + 1);
		}
		if ((next_tick_ts & 15) != r.charCodeAt(r.length - 3) - 97 || (next_tick_ts & 240) >> 4 != r.charCodeAt(r.length - 2) - 65 || (next_tick_ts & 1792) >> 8 != r.charCodeAt(r.length - 1) - 48) {
			return -1;
		}
		part = r.substring(0, r.length - 3);
		return 0;
	}
	if (0 == r.length && 0 != part.length) {
		s = part;
		/** @type {string} */
		part = "";
		error();
		update();
	}
	return -1;
}
/**
 * @param {number} i
 * @param {number} value
 * @param {number} id
 * @return {undefined}
 */
function create(i, value, id) {
	if (0 == wb) {
		if (i) {
			/** @type {number} */
			num = i;
		}
		if ("0" == value) {
			/** @type {boolean} */
			isFriend = true;
		}
		if (id) {
			/** @type {number} */
			deps = id;
		}
		drawPlayButton();
		self.e("font.gif", 8, 12);
		tmp.e("wheel.gif");
		if (closeDropdownsIn()) {
			wb--;
		} else {
			wb++;
		}
	}
	if (1 == wb) {
		draw(self.o);
		draw(tmp);
		if (0 != Cb) {
			emit(create, sendMessage());
		} else {
			wb++;
		}
	}
	if (2 == wb) {
		if (0 == num.length) {
			/** @type {number} */
			baseFooterClass = 2;
			/** @type {number} */
			lb = 1;
		}
		if (0 != deps.length) {
			/** @type {number} */
			baseFooterClass = 2;
			/** @type {number} */
			lb = 3;
		}
		mockObject.e(0);
		/** @type {!Array} */
		results = Array(12E4);
		/** @type {!Array} */
		state = Array(12E4);
		/** @type {!Array} */
		parts = Array(12E4);
		/** @type {!Array} */
		ret = Array(12E4);
		css();
		if (0 < deps.length) {
			s = load(deps, "");
			if (1 == Hb) {
				error();
				update();
				/** @type {number} */
				gasSum = costSum = 1;
			} else {
				/** @type {number} */
				costSum = 2;
			}
		}
		css();
		html();
		/** @type {number} */
		i = 0;
		for (; i < settings.length; i++) {
			value = parseInt((2989 * (settings[i][0] >> 16 & 255) + 5866 * (settings[i][0] >> 8 & 255) + 1145 * (settings[i][0] & 255)) / 1E4);
			/** @type {number} */
			channels[i] = value << 16 | value << 8 | value;
		}
		drawLine(0, 0, length, height, 4210752);
		drawText(211, 451, points, -1, 0, -1);
		self.a(16, 311, "POWDER", 15908203, 0);
		self.a(16, 325, "WATER", 4210943, 0);
		self.a(16, 339, "FIRE", 16728128, 0);
		self.a(16, 353, "SEED", 9486400, 0);
		drawText(16, 367, "G-POWDER", -1, 0, -2);
		drawText(16, 367, "G-POWDER", 11567184, -1, -2);
		self.a(16, 381, "FAN", 8421631, 0);
		self.a(16, 395, "ICE", 13684991, 0);
		self.a(16, 409, "S-BALL", 16728224, 0);
		self.a(16, 423, "CLONE", 9465872, 0);
		drawText(16, 437, "F-WORKS", 16750950, 0, -1);
		self.a(72, 311, "OIL", 8400928, 0);
		self.a(72, 325, "C-4", 16777164, 0);
		self.a(72, 339, "STONE", 8421504, 0);
		self.a(72, 353, "MAGMA", 16737843, 0);
		self.a(72, 367, "VIRUS", 8388736, 0);
		self.a(72, 381, "NITRO", 4486912, 0);
		self.a(72, 395, "ANT", 12615872, 0);
		self.a(72, 409, "TORCH", 16752672, 0);
		self.a(72, 423, "GAS", 13408665, 0);
		self.a(72, 437, "SOAPY", 14737632, 0);
		drawText(128, 311, "THUNDER", 16776992, 0, -1);
		self.a(128, 325, "METAL", 4210752, 0);
		self.a(128, 339, "BOMB", 6710784, 0);
		self.a(128, 353, "LASER", 13369344, 0);
		self.a(128, 367, "ACID", 13434624, 0);
		self.a(128, 381, "VINE", 47872, 0);
		self.a(128, 395, "SALT", 16777215, 0);
		self.a(128, 409, "GLASS", 4210752, 0);
		self.a(128, 423, "BIRD", 8417360, 0);
		drawText(128, 437, "MERCURY", 11184810, 0, -1);
		self.a(184, 311, "SPARK", 16763955, 0);
		self.a(184, 325, "FUSE", 4469538, 0);
		self.a(184, 339, "CLOUD", 13421772, 0);
		self.a(184, 353, "PUMP", 13107, 0);
		self.a(240, 311, "WIND", 8421631, 0);
		self.a(240, 325, "AIR", 8421631, 0);
		self.a(240, 339, "DRAG", 16777215, 0);
		self.a(240, 353, "B", 16769248, 0);
		self.a(240, 353, " U", 16777184, 0);
		self.a(240, 353, "  B", 14745568, 0);
		self.a(240, 353, "	B", 14745599, 0);
		self.a(240, 353, "	 L", 14737663, 0);
		self.a(240, 353, "	  E", 16769279, 0);
		self.a(240, 367, "WHEEL", 11575440, 0);
		self.a(240, 381, "PLAYER", 15908203, 0);
		drawText(240, 395, "FIGHTER", 15908203, 0, -1);
		self.a(240, 409, "BOX", 15908203, 0);
		self.a(240, 423, "BALL", 15908203, 0);
		self.a(240, 437, "CREATE", 9465872, 0);
		self.a(296, 311, "BLOCK", 8421504, 0);
		self.a(296, 325, "ERASE", 8421504, 0);
		self.a(296, 339, "CLEAR", 16777215, 0);
		drawText(295, 353, "Copy", -1, 0, -2);
		drawText(295, 353, "Copy", 16777215, -1, -2);
		drawText(319, 353, "Paste", -1, 0, -3);
		drawText(319, 353, "Paste", 16777215, -1, -3);
		self.a(296, 367, "TEXT", 16777215, 0);
		drawText(296, 381, "PEN", -1, 0, -1);
		drawText(296, 381, "PEN", 16777215, -1, -1);
		drawText(296, 395, "PEN-S ", 16777215, 0, -1);
		drawText(296, 409, "SCALE", 16777215, 0, -1);
		drawText(296, 423, "SPEEDx", 16777215, 0, -1);
		drawText(295, 437, "Start", -1, 0, -3);
		drawText(295, 437, "Start", 16777215, -1, -3);
		drawText(321, 437, "Stop", -1, 0, -2);
		drawText(321, 437, "Stop", 16777215, -1, -2);
		self.a(352, 311, "UPLOAD", 16752800, 0);
		self.a(352, 325, "SAVE", 16752800, 0);
		self.a(352, 339, "LOAD", 16752800, 0);
		drawText(352, 353, "MiniMap", 16752800, 0, -1);
		drawText(352, 367, "MENU-", -1, 0, -2);
		drawText(352, 367, "MENU-", 16777215, -1, -2);
		drawText(352, 381, "SIDE-", -1, 0, -3);
		drawText(352, 381, "SIDE-", 16777215, -1, -3);
		self.a(352, 395, "GRID", 8388608, 0);
		drawText(352, 409, "BG-", -1, 0, -2);
		drawText(352, 409, "BG-", 16777215, -1, -2);
		self.a(352, 423, "DOT ", 16777215, 0);
		self.a(352, 437, "RESET", 16777215, 0);
		drawText(64, 451, "x		y", -1, 0, -1);
		drawText(141, 451, "dot", -1, 0, -1);
		test(input, length, height);
		/** @type {number} */
		i = 0;
		for (; i < length * height; i++) {
			/** @type {number} */
			input.b[i] = pixels[i];
		}
		/** @type {number} */
		i = length * height - 1;
		for (; 0 <= i; i--) {
			/** @type {number} */
			pixels[i] = 0;
		}
		resolve();
	}
}
/**
 * @return {undefined}
 */
function init() {
	if (0 < Pb) {
		Pb++;
	} else {
		editorAt("");
		createElement("");
		var i;
		var x;
		var offset;
		var item;
		var c;
		var data;
		x = lat;
		offset = lon;
		if (300 <= offset && (historyInstance || hasToggledVideo) && false == extreme) {
			/** @type {boolean} */
			extreme = true;
		} else {
			if (300 > offset && true == extreme) {
				/** @type {boolean} */
				extreme = false;
			}
		}
		mockObject.move();
		mockObject.a();
		/** @type {number} */
		item = 12;
		/** @type {number} */
		c = 311;
		/** @type {number} */
		i = 308 * length;
		/** @type {number} */
		data = length * height;
		for (; i < data; i++) {
			pixels[i] = input.b[i];
		}
		if (1 == next) {
			drawLine(item + 4 + 0 + 8, c + 0, 48, 137, 4210752);
			drawLine(item + 4 + 56 + 8, c + 0, 48, 137, 4210752);
			drawLine(item + 4 + 112 + 8, c + 0, 48, 137, 4210752);
			drawLine(item + 4 + 168 + 8, c + 0, 48, 53, 4210752);
			drawLine(item + 4 + 224 + 8, c + 42, 47, 53, 4210752);
			drawLine(item + 4 + 224 + 16, c + 98, 39, 25, 4210752);
			drawLine(item + 4 + 224 + 8, c + 126, 47, 11, 4210752);
			drawLine(item + 4 + 112 + 8 - 1, c + 0 + 4, 1, 7, 4210752);
			/** @type {!Array} */
			data = Array(48);
			/** @type {number} */
			i = 0;
			for (; i < data.length; i++) {
				/** @type {number} */
				data[i] = 0;
			}
			/** @type {number} */
			i = 0;
			for (; i < k; i++) {
				data[args[i]]++;
			}
			drawText(item + 4 + 0, c + 0, "	" + data[_], 15908203, 0, -1);
			drawText(item + 4 + 0, c + 14, "	 " + data[name], 4210943, 0, -1);
			drawText(item + 4 + 0, c + 28, "	 " + data[options], 16728128, 0, -1);
			drawText(item + 4 + 0, c + 42, "	 " + data[number], 9486400, 0, -1);
			drawText(item + 4 + 0, c + 56, "	 " + data[message], 11567184, 0, -1);
			drawText(item + 4 + 0, c + 70, "	 " + data[id], 8421631, 0, -1);
			drawText(item + 4 + 0, c + 84, "	 " + data[current], 13684991, 0, -1);
			drawText(item + 4 + 0, c + 98, "	 " + data[line], 16728224, 0, -1);
			drawText(item + 4 + 0, c + 112, "  " + data[string], 9465872, 0, -1);
			drawText(item + 4 + 0, c + 126, "  " + data[all], 16750950, 0, -1);
			drawText(item + 4 + 56, c + 0, "	 " + data[r], 8400928, 0, -1);
			drawText(item + 4 + 56, c + 14, "  " + data[command], 16777164, 0, -1);
			drawText(item + 4 + 56, c + 28, "  " + data[tag], 8421504, 0, -1);
			drawText(item + 4 + 56, c + 42, "  " + data[object], 16737843, 0, -1);
			drawText(item + 4 + 56, c + 56, "  " + data[delimiter], 8388736, 0, -1);
			drawText(item + 4 + 56, c + 70, "  " + data[code], 4486912, 0, -1);
			drawText(item + 4 + 56, c + 84, "  " + data[group], 12615872, 0, -1);
			drawText(item + 4 + 56, c + 98, "  " + data[elem], 16752672, 0, -1);
			drawText(item + 4 + 56, c + 112, "	" + data[date], 13408665, 0, -1);
			drawText(item + 4 + 56, c + 126, "	" + data[v], 14737632, 0, -1);
			drawText(item + 4 + 112, c + 0, "  " + data[end], 16776992, 0, -1);
			drawText(item + 4 + 112, c + 14, "	" + data[val], 4210752, 0, -1);
			drawText(item + 4 + 112, c + 28, "	" + data[host], 6710784, 0, -1);
			drawText(item + 4 + 112, c + 42, "	" + data[title], 13369344, 0, -1);
			drawText(item + 4 + 112, c + 56, "	" + data[parent], 13434624, 0, -1);
			drawText(item + 4 + 112, c + 70, "	" + data[p], 47872, 0, -1);
			drawText(item + 4 + 112, c + 84, "	" + data[size], 16777215, 0, -1);
			drawText(item + 4 + 112, c + 98, "	" + data[key], 4210752, 0, -1);
			drawText(item + 4 + 112, c + 112, "	 " + data[node], 8417360, 0, -1);
			drawText(item + 4 + 112, c + 126, "	 " + data[undefined], 11184810, 0, -1);
			drawText(item + 4 + 168, c + 0, "  " + data[event], 16763955, 0, -1);
			drawText(item + 4 + 168, c + 14, "	" + data[action], 4469538, 0, -1);
			drawText(item + 4 + 168, c + 28, "	" + data[h], 13421772, 0, -1);
			drawText(item + 4 + 168, c + 42, "	" + data[none], 13107, 0, -1);
			drawText(item + 4 + 224, c + 42, "	" + data[n], 16769248, 0, -1);
			drawText(item + 4 + 224, c + 56, "	" + idx, 11575440, 0, -1);
			/** @type {number} */
			i = 0;
			for (; 5 > i; i++) {
				/** @type {number} */
				data[i] = 0;
			}
			/** @type {number} */
			i = 0;
			for (; i < to; i++) {
				if (rows[i] >= auto) {
					data[4]++;
				} else {
					if (rows[i] >= float) {
						data[2]++;
					} else {
						if (rows[i] >= tr) {
							data[1]++;
						} else {
							if (rows[i] >= item) {
								data[0]++;
							}
						}
					}
				}
			}
			drawText(item + 4 + 224, c + 70, "	" + data[2], 15908203, 0, -1);
			drawText(item + 4 + 224, c + 84, "	" + data[0], 15908203, 0, -1);
			drawText(item + 4 + 224, c + 98, "	 " + data[1], 15908203, 0, -1);
			/** @type {number} */
			i = 0;
			for (; i < _len; i++) {
				if (0 != plugins[i]) {
					data[3]++;
				}
			}
			drawText(item + 4 + 224, c + 112, "	  " + data[3], 15908203, 0, -1);
			drawText(item + 4 + 224, c + 126, "	 " + data[4], 9465872, 0, -1);
		}
		if (historyInstance && 0 == evalID) {
			if (box["0"]) {
				/** @type {number} */
				w = 0;
			} else {
				if (box["1"]) {
					/** @type {number} */
					w = 1;
				} else {
					if (box["2"]) {
						/** @type {number} */
						w = 2;
					} else {
						if (box["3"]) {
							/** @type {number} */
							w = 3;
						} else {
							if (box["4"]) {
								/** @type {number} */
								w = 4;
							} else {
								if (box["5"]) {
									/** @type {number} */
									w = 5;
								} else {
									if (box["6"]) {
										/** @type {number} */
										w = 6;
									} else {
										if (box["7"]) {
											/** @type {number} */
											w = 7;
										} else {
											if (box["8"]) {
												/** @type {number} */
												w = 8;
											} else {
												if (box["9"]) {
													/** @type {number} */
													w = 9;
												} else {
													if (box[32]) {
														gasSum = fn(gasSum + 1, 1);
													} else {
														if (box[10] || box[13]) {
															/** @type {number} */
															gasSum = 1;
														} else {
															if (box.l) {
																error();
																update();
																/** @type {number} */
																ja = -10;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (repeat(item - 8, c - 8, 391, 139) && extreme && 0 == evalID) {
			x = parseInt((x - (item - 8)) / 56);
			offset = parseInt((offset - (c - 8)) / 14);
			i = clamp(10 * x + offset, 0, 69);
			if (34 != i && 35 != i && 36 != i && 37 != i && 38 != i && 39 != i) {
				if (53 == i) {
					if (hasToggledVideo) {
						if (53 == url) {
							/** @type {number} */
							COLON = 1 - COLON;
						}
						url = i;
					}
					if (hasToggledAudio) {
						if (53 == l) {
							/** @type {number} */
							COLON = 1 - COLON;
						}
						l = i;
					}
				} else {
					if (55 == i) {
						bx1 = fn(bx1 + dx, 3);
					} else {
						if (56 == i) {
							w = fn(w + dx, 9);
						} else {
							if (57 == i) {
								if (hasToggledVideo) {
									if (57 == url && 4 > tileSize) {
										tileSize++;
										time = time + (400 >> tileSize >> 1);
										delta = delta + (300 >> tileSize >> 1);
									} else {
										if (57 == url) {
											/** @type {number} */
											tileSize = 0;
										}
									}
									url = i;
								} else {
									if (hasToggledAudio) {
										if (57 == l && 0 < tileSize) {
											/** @type {number} */
											time = time - (400 >> tileSize >> 1);
											/** @type {number} */
											delta = delta - (300 >> tileSize >> 1);
											tileSize--;
										} else {
											if (57 == l) {
												/** @type {number} */
												tileSize = 4;
												time = time + (200 - (400 >> tileSize >> 1));
												delta = delta + (150 - (300 >> tileSize >> 1));
											}
										}
										l = i;
									}
								}
								time = clamp(time, 0, 400 - (400 >> tileSize));
								delta = clamp(delta, 0, 300 - [300, 150, 75, 38, 19][tileSize]);
							} else {
								if (58 == i) {
									type = fn(type + dx, 3);
								} else {
									if (59 == i) {
										gasSum = fn(gasSum + dx, 1);
									} else {
										if (60 == i) {
											if (0 != dx) {
												/** @type {number} */
												evalID = 1;
											}
										} else {
											if (61 == i) {
												if (hasToggledVideo || hasToggledAudio) {
													css();
													html();
													/** @type {number} */
													ja = 10;
												}
											} else {
												if (62 == i) {
													if (0 != dx) {
														error();
														update();
														/** @type {number} */
														ja = -10;
													}
												} else {
													if (63 == i) {
														endAttachX = fn(endAttachX + dx, 1);
													} else {
														if (64 == i) {
															next = fn(next + dx, 1);
														} else {
															if (65 == i) {
																option = fn(option + dx, 1);
															} else {
																if (66 == i) {
																	err = fn(err + dx, 7);
																} else {
																	if (67 == i) {
																		if (i1 = fn(i1 + dx, 13), 0 != dx) {
																			/** @type {number} */
																			i = 309 * length - 1;
																			for (; 0 <= i; i--) {
																				/** @type {number} */
																				buffer[i] = 0;
																				/** @type {number} */
																				sprites[i] = 0;
																				/** @type {number} */
																				elements[i] = 0;
																			}
																		}
																	} else {
																		if (68 == i) {
																			max = fn(max + dx, 2);
																		} else {
																			if (69 == i) {
																				if (0 != dx) {
																					mockObject.e(0);
																				}
																			} else {
																				if (hasToggledVideo) {
																					url = i;
																				} else {
																					if (hasToggledAudio) {
																						l = i;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			/** @type {number} */
			i = item + 0 + 56 * x;
			/** @type {number} */
			x = c - 1 + 14 * offset;
			/** @type {number} */
			offset = 56;
			/** @type {number} */
			data = 13;
			var k;
			var index;
			var len;
			offset = i + offset > length ? length : parseInt(i + offset);
			data = x + data > height ? height : parseInt(x + data);
			i = 0 > i ? 0 : parseInt(i);
			x = 0 > x ? 0 : parseInt(x);
			index = x * length + i;
			/** @type {number} */
			len = length - (offset - i);
			for (; x < data; x++, index = index + len) {
				k = i;
				for (; k < offset; k++, index++) {
					if (4210752 == pixels[index] >>> 0) {
						/** @type {number} */
						pixels[index] = 4194304;
					}
				}
			}
		}
		if (extreme) {
			add(8, 308, 408, 308, 6684672);
		}
		if (0 == COLON) {
			drawText(item + 4 + 280 - 1, c + 42, "Copy", 16728128, -1, -2);
		} else {
			drawText(item + 4 + 280 + 23, c + 42, "Paste", 16728128, -1, -3);
		}
		/** @type {!Array} */
		i = ["free", "line", "lock", "paint"];
		drawText(item + 4 + 280, c + 70, "	  " + i[bx1], -1, 0, -2);
		drawText(item + 4 + 280, c + 70, "	  " + i[bx1], 16777215, -1, -2);
		drawText(item + 4 + 280 - 1, c + 84, "		  " + w, 16777215, 0, -1);
		drawText(item + 4 + 280, c + 98, "		 " + ["x1", "x2", "x4", "x8", "16"][tileSize], 16777215, 0, -2);
		drawText(item + 4 + 280, c + 112, "			" + (1 << type), 16777215, 0, -2);
		if (0 == gasSum) {
			drawText(item + 4 + 280 - 1, c + 126, "Start", 16728128, -1, -3);
		} else {
			drawText(item + 4 + 280 + 25, c + 126, "Stop", 16728128, -1, -2);
		}
		if (0 < ja) {
			ja--;
			if (1 < ja) {
				self.a(item + 4 + 336, c + 14, "SAVE", 16777215, 16711680);
			}
		}
		if (0 > ja) {
			ja++;
			if (-1 > ja) {
				self.a(item + 4 + 336, c + 28, "LOAD", 16777215, 16711680);
			}
		}
		if (1 == endAttachX) {
			drawText(item + 4 + 336, c + 42, "MiniMap", 16777215, 16711680, -1);
		}
		/** @type {!Array} */
		i = ["str", "num"];
		drawText(item + 4 + 336, c + 56, "		" + i[next], -1, 0, -2);
		drawText(item + 4 + 336, c + 56, "		" + i[next], 16777215, -1, -2);
		/** @type {!Array} */
		i = ["OFF", "LOOP"];
		drawText(item + 4 + 336 + 25, c + 70, i[option], -1, 0, -2);
		drawText(item + 4 + 336 + 25, c + 70, i[option], 16777215, -1, -2);
		self.a(item + 4 + 336, c + 84, "		 " + err, 8388608, 0);
		/** @type {!Array<string>} */
		i = "non air line blur shade aura light toon mesh gray track dark TG siluet".split(" ");
		drawText(item + 4 + 336, c + 98, "	 " + i[i1], -1, 0, -2);
		drawText(item + 4 + 336, c + 98, "	 " + i[i1], 16777215, -1, -2);
		self.a(item + 4 + 336, c + 112, "	 " + ["S", "M", "L"][max], 16777215, 0);
		drawLine(item + 0 + 56 * parseInt(url / 10), c + 1 + url % 10 * 14, 3, 4, 16711680);
		drawLine(item + 0 + 56 * parseInt(l / 10), c + 6 + l % 10 * 14, 3, 4, 255);
		drawText(64, 451, " " + (value - 8), -1, 0, -1);
		drawText(64, 451, "		 " + (y - 8), -1, 0, -1);
		drawText(141, 451, "	  " + (beginHint[max] - k), -1, 0, -1);
		self.a(16, 451, path + fileName, -1, 0);
		if (1 == aa) {
			self.a(64, 451, level + "sl", 16777215, 0);
		}
		if (1 == endAttachX) {
			/** @type {number} */
			item = 15;
			/** @type {number} */
			c = 314;
			if (116 > lat && extreme) {
				/** @type {number} */
				item = 127;
			}
			drawLine(item - 3, c - 3, 106, 81, 8421504);
			css();
			/** @type {number} */
			i = 0;
			/** @type {number} */
			item = length * c + item;
			/** @type {number} */
			offset = 0;
			for (; 300 > offset; offset = offset + 4, item = item + (length - 100)) {
				/** @type {number} */
				x = 0;
				for (; 400 > x; x = x + 4, item++) {
					/** @type {number} */
					c = 400 * offset + x;
					if (0 == parts[c]) {
						/** @type {number} */
						c = c + 401;
					}
					i = 11 == i1 ? parts[c] == options || parts[c] == object || parts[c] == elem || parts[c] == end || parts[c] == title || parts[c] == event ? parts[c] : 0 : 13 == i1 ? 0 == parts[c] ? 0 : 1 : parts[c];
					pixels[item] = 9 == i1 ? channels[i] : 13 == i1 ? 0 == i ? 16777215 : 0 : settings[i][0];
				}
			}
		}
		if (-1 == evalID) {
			evalID++;
		}
		if (1 == costSum) {
			if (isFriend) {
				generate(str, "\u30af\u30ea\u30c3\u30af\u3067\u518d\u751f\u3001\uff2c\uff2f\uff21\uff24\u3067\u518d\u30b9\u30bf\u30fc\u30c8");
			} else {
				generate(str, "Click to play, LOAD to restart.");
			}
			/** @type {number} */
			costSum = 0;
			/** @type {number} */
			evalID = 10;
		} else {
			if (2 == costSum) {
				if (isFriend) {
					generate(str, "\u30a8\u30e9\u30fc");
				} else {
					generate(str, "Error");
				}
				/** @type {number} */
				costSum = 0;
				/** @type {number} */
				evalID = 10;
			}
		}
		if (1 == evalID) {
			/** @type {number} */
			tileSize = 0;
			if (0 == baseFooterClass) {
				/** @type {string} */
				item = $(47, 115, 99, 111, 114, 101, 47, 100, 117, 115, 116, 49, 46, 112, 104, 112, 63, 97, 61);
				item = item + num;
				/** @type {string} */
				item = item + (QUERY_PREFIX + (isFriend ? "0" : "1"));
				load(item, "");
				if (1 == Hb && "ok" == markup_classes[0]) {
					/** @type {number} */
					baseFooterClass = 1;
				} else {
					/** @type {number} */
					baseFooterClass = 2;
					/** @type {number} */
					lb = "err1" == markup_classes[0] ? 1 : "err2" == markup_classes[0] ? 2 : "err3" == markup_classes[0] ? 3 : "err4" == markup_classes[0] ? 4 : "err5" == markup_classes[0] ? 5 : 0;
				}
			}
			evalID++;
		}
		if (2 == evalID) {
			if (1 == baseFooterClass) {
				if (50 > z) {
					/** @type {number} */
					evalID = 3;
					if (isFriend) {
						generate(str, "\u3082\u3046\u5c11\u3057\u4f5c\u308a\u8fbc\u3093\u3067\u4e0b\u3055\u3044\u3002");
					} else {
						generate(str, "Please carefully created.");
					}
					return;
				}
				if (isFriend) {
					generate(str, "\u30bf\u30a4\u30c8\u30eb\u3092\u8a18\u5165\u3057\u3066\uff2f\uff2b\u3092\u62bc\u3057\u3066\u4e0b\u3055\u3044");
				} else {
					generate(str, "Enter the title and click OK.");
				}
				/** @type {string} */
				file = "";
			} else {
				if (2 == baseFooterClass) {
					if (isFriend) {
						if (1 == lb) {
							generate(str, "\u30e6\u30fc\u30b6\u30fc\u767b\u9332\u304c\u5fc5\u8981\u3067\u3059");
						} else {
							if (2 == lb) {
								generate(str, "1\u65e5\u306b1\u56de\u306e\u307f\u3067\u3059");
							} else {
								if (3 == lb) {
									generate(str, "\u30c0\u30a6\u30f3\u30ed\u30fc\u30c9\u30c7\u30fc\u30bf");
								} else {
									if (4 == lb) {
										generate(str, "\u904e\u53bb12\u6642\u9593\u306e\u4f5c\u54c1\u6570\u304c50\u4ef6\u306b\u9054\u3057\u305f\u70ba\uff71\uff6f\uff8c\uff9f\u51fa\u6765\u307e\u305b\u3093");
									} else {
										if (5 == lb) {
											generate(str, "\u8a00\u8a9e\u30a8\u30e9\u30fc");
										} else {
											generate(str, "\u30a2\u30c3\u30d7\u30ed\u30fc\u30c9\u51fa\u6765\u307e\u305b\u3093");
										}
									}
								}
							}
						}
					} else {
						if (1 == lb) {
							generate(str, "User registration is required.");
						} else {
							if (2 == lb) {
								generate(str, "1 time in 1 days only.");
							} else {
								if (3 == lb) {
									generate(str, "Download data.");
								} else {
									if (4 == lb) {
										generate(str, "Reached 50 posts in 12 hours. Cannot upload.");
									} else {
										if (5 == lb) {
											generate(str, "Language error.");
										} else {
											generate(str, "Cannot upload.");
										}
									}
								}
							}
						}
					}
				}
			}
			evalID++;
		} else {
			if (3 == evalID) {
				drawLine(48, 100, 320, 100, 8421504);
				show(208, 110, "UPLOAD", 16752800);
				addMemberToDiscussion(135);
				if (1 == baseFooterClass && 50 <= z && (drawLine(92, 150, 232, 16, 16777215), filter(91, 149, 234, 18, 0), repeat(84, 142, 232, 16) && (filter(91, 149, 234, 18, 16711680), rx && (item = extend("Text", file), null != item && (file = item))), generate(arg, file), append(arg, 93, 150, 230, 16, 230, 16, 4278190080), item = repeat(150, 172, 16, 12), self.a(158, 180, "OK", item ? 
																																																																																																																										16711680 : 16777215, 0), item && rx)) {
					if (2 > file.length) {
						if (isFriend) {
							generate(str, "\u30bf\u30a4\u30c8\u30eb\u3092\uff12\u6587\u5b57\u4ee5\u4e0a\u8a18\u5165\u3057\u3066\u4e0b\u3055\u3044");
						} else {
							generate(str, "The title must be longer than 2 characters.");
						}
					} else {
						item = file;
						/** @type {number} */
						c = 0;
						i = item.length;
						/** @type {number} */
						x = 0;
						for (; x < i; x++) {
							offset = item.charCodeAt(x);
							/** @type {number} */
							c = 0 <= offset && 128 >= offset || 65377 <= offset && 65439 >= offset ? c + 1 : c + 2;
						}
						if (20 < c) {
							if (isFriend) {
								generate(str, "\u30bf\u30a4\u30c8\u30eb\u3092\uff11\uff10\u6587\u5b57\u4ee5\u4e0b\u3067\u8a18\u5165\u3057\u3066\u4e0b\u3055\u3044");
							} else {
								generate(str, "The title must be shorter than 10 characters.");
							}
						} else {
							evalID++;
						}
					}
				}
				item = repeat(200, 172, 48, 12);
				self.a(208, 180, "CANCEL", item ? 16711680 : 16777215, 0);
				if (item && rx) {
					/** @type {number} */
					evalID = 5;
				}
			} else {
				if (4 == evalID) {
					/** @type {string} */
					file = encodeURIComponent(file);
					if (0 == file.length) {
						/** @type {number} */
						evalID = 3;
						if (isFriend) {
							generate(str, "\u30a8\u30e9\u30fc");
						} else {
							generate(str, "Error");
						}
					} else {
						css();
						html();
						if (605 == s.length) {
							/** @type {number} */
							evalID = 3;
							if (isFriend) {
								generate(str, "\u30a8\u30e9\u30fc");
							} else {
								generate(str, "Error");
							}
						} else {
							/** @type {string} */
							item = $(47, 115, 99, 111, 114, 101, 47, 100, 117, 115, 116, 49, 46, 112, 104, 112, 63, 97, 61);
							item = item + num;
							/** @type {string} */
							item = item + (QUERY_PREFIX + (isFriend ? "0" : "1"));
							/** @type {string} */
							item = item + (start + file);
							c = "d=" + s;
							c = c + (tab + sum);
							c = c + (advice + className);
							c = c + (tiles + zoom);
							load(item, c);
							/** @type {number} */
							baseFooterClass = 2;
							evalID++;
						}
					}
				} else {
					if (5 == evalID) {
						/** @type {number} */
						evalID = 0;
					} else {
						if (10 == evalID) {
							if (drawLine(82, 308, 252, 70, 6291456), drawLine(86, 312, 244, 62, 6316128), show(208, 322, "DOWNLOAD", 16752800), addMemberToDiscussion(343), 200 > lat ? (show(178, 365, "START", 16711680), show(238, 365, "STOP", 16777215)) : (show(178, 365, "START", 16777215), show(238, 365, "STOP", 16711680)), rx) {
								/** @type {number} */
								evalID = 0;
								/** @type {number} */
								gasSum = 200 > lat ? 0 : 1;
							} else {
								if (pairs[37] || pairs[39]) {
									/** @type {number} */
									evalID = 0;
									/** @type {number} */
									gasSum = pairs[37] ? 0 : 1;
								}
							}
						} else {
							if (20 == evalID) {
								/** @type {string} */
								file = "";
								evalID++;
							} else {
								if (21 == evalID) {
									drawLine(88, 309, 240, 99, 8421504);
									drawLine(92, 317, 232, 16, 16777215);
									filter(91, 316, 234, 18, 0);
									if (repeat(84, 309, 232, 16)) {
										filter(91, 316, 234, 18, 16711680);
										if (rx) {
											item = extend("Text", file);
											if (null != item) {
												file = item;
											}
										}
									}
									self.a(93, 320, file.substr(0, 28), 16777215, 0);
									if (3 == collector) {
										drawLine(240, 340, 84, 16, 16777215);
										filter(239, 339, 86, 18, 0);
										if (repeat(232, 332, 84, 16)) {
											filter(239, 339, 86, 18, 16711680);
											if (rx) {
												item = extend("setFont", request);
												if (null != item) {
													request = item;
												}
											}
										}
										self.a(241, 343, request.substr(0, 10), 16777215, 0);
									}
									/** @type {number} */
									i = -1;
									if (80 <= lat && 220 > lat && 334 <= lon && 382 > lon) {
										i = parseInt((lon - 334) / 16);
										if (0 == i && 0 != dx) {
											collector = fn(collector + dx, 3);
										}
										if (1 == i && 0 != dx) {
											x = fn(x + dx, 3);
										}
										if (2 == i && 0 != dx) {
											signedTransactionsCounter = fn(signedTransactionsCounter + dx, 10);
										}
									}
									self.a(92, 342, "font :" + historical_metrics[collector], 0 == i ? 16711680 : 16777215, 0);
									self.a(92, 358, "style:" + methods[x], 1 == i ? 16711680 : 16777215, 0);
									self.a(92, 374, "size :" + signedTransactions[signedTransactionsCounter], 2 == i ? 16711680 : 16777215, 0);
									/** @type {number} */
									i = -1;
									if (80 <= lat && 320 > lat && 382 <= lon && 400 > lon) {
										/** @type {number} */
										i = 200 > lat ? 0 : 1;
										if (rx) {
											if (0 == i) {
												evalID++;
											} else {
												/** @type {number} */
												evalID = 23;
											}
										}
									}
									self.a(158, 392, "OK", 0 == i ? 16711680 : 16777215, 0);
									self.a(208, 392, "CANCEL", 1 == i ? 16711680 : 16777215, 0);
									item = historical_metrics[collector];
									if (3 == collector) {
										item = request;
									}
									render(arg, file, item, x, signedTransactions[signedTransactionsCounter]);
									/** @type {number} */
									item = _;
									if (0 != types[url]) {
										item = types[url];
									} else {
										if (0 != types[l]) {
											item = types[l];
										}
									}
									if (item == key) {
										/** @type {number} */
										item = _;
									}
									append(arg, a, d, arg.g, 128, arg.g, 128, settings[item][0]);
								} else {
									if (22 == evalID) {
										/** @type {!Array<string>} */
										item = "sex gay fuck suck crap shit dick penis bitch ** \u30bb\u30c3\u30af\u30b9 \u30a8\u30c3\u30c1 \u3061\u3093\u3053 \u30c1\u30f3\u30b3 \u307e\u3093\u3053 \u30de\u30f3\u30b3 \u539f\u7206 \u539f\u5b50\u7206 \u6838 \u88ab\u7206 \u6b7b \u6bba \u7968 \u8a55 \u62cd\u624b \u4eba\u6c17 \u53c2\u52a0 \u30a2\u30f3\u30b1\u30fc\u30c8 \u524a\u9664 \u6d88\u53bb ttp www. .com .jp".split(" ");
										/** @type {string} */
										c = "";
										/** @type {number} */
										i = 0;
										for (; i < file.length; i++) {
											x = file[i];
											if (" " != x && "\u3000" != x) {
												/** @type {string} */
												c = c + x;
											}
										}
										/** @type {string} */
										c = c.toLowerCase();
										/** @type {number} */
										i = 0;
										for (; i < item.length && !(0 <= c.indexOf(item[i])); i++) {
										}
										if (i != item.length) {
											/** @type {number} */
											evalID = 23;
										} else {
											item = historical_metrics[collector];
											if (3 == collector) {
												item = request;
											}
											render(arg, file, item, x, signedTransactions[signedTransactionsCounter]);
											/** @type {number} */
											item = _;
											if (0 != types[url]) {
												item = types[url];
											} else {
												if (0 != types[l]) {
													item = types[l];
												}
											}
											if (item == key) {
												/** @type {number} */
												item = _;
											}
											/** @type {number} */
											offset = 0;
											for (; 128 > offset && !(308 <= d + offset); offset++) {
												/** @type {number} */
												x = 0;
												for (; 400 > x && !(408 <= a + x); x++) {
													if (-1 != arg.b[offset * arg.c + x] && obj[(d + offset) * length + (a + x)] == element) {
														c = callback(a + x, d + offset, item);
														if (0 <= c && item == id) {
															/** @type {number} */
															items[c].x = 0.1 * expected.x;
															/** @type {number} */
															items[c].y = 0.1 * expected.y;
															/** @type {number} */
															obj[(d + offset) * length + (a + x)] = temp;
														}
													}
												}
											}
											evalID++;
										}
									} else {
										if (23 == evalID) {
											/** @type {number} */
											evalID = 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
/**
 * @return {undefined}
 */
function e() {
}
/**
 * @return {undefined}
 */
function css() {
	var i;
	var x;
	var rowNumber;
	var index;
	/** @type {number} */
	i = 0;
	for (; 12E4 > i; i++) {
		/** @type {number} */
		parts[i] = 0;
		/** @type {number} */
		ret[i] = 0;
	}
	/** @type {number} */
	rowNumber = 0;
	for (; 300 > rowNumber; rowNumber++) {
		/** @type {number} */
		x = 0;
		for (; 400 > x; x++) {
			/** @type {number} */
			index = ((rowNumber >> 2) + 2) * step + ((x >> 2) + 2);
			if (1 == out[index]) {
				/** @type {number} */
				parts[400 * rowNumber + x] = 1;
			}
		}
	}
	/** @type {number} */
	i = 0;
	for (; i < k; i++) {
		x = parseInt(params[i].x);
		rowNumber = parseInt(params[i].y);
		if (!(8 > x || 408 <= x || 8 > rowNumber || 308 <= rowNumber)) {
			/** @type {number} */
			x = x - 8;
			/** @type {number} */
			rowNumber = rowNumber - 8;
			index = 400 * rowNumber + x;
			/** @type {number} */
			parts[index] = args[i];
			if (args[i] == id) {
				ret[index] = fn(parseInt(64 * angle(items[i]) / firstX), 63);
			} else {
				if (args[i] == all) {
					/** @type {number} */
					ret[index] = arr[i] % 100;
				}
			}
		}
	}
	/** @type {number} */
	i = 0;
	for (; i < idx; i++) {
		/** @type {number} */
		index = 400 * (tokens[i] - 8) + (times[i] - 8);
		/** @type {number} */
		parts[index] = 9;
		/** @type {number} */
		ret[index] = 0;
	}
	/** @type {number} */
	i = 0;
	for (; i < to; i++) {
		/** @type {number} */
		index = i * stride;
		if (rows[i] == item || rows[i] == item + 1) {
			x = parseInt(vertices[index + 4].x);
			rowNumber = parseInt(vertices[index + 4].y);
			if (!(8 > x || length - 8 <= x || 8 > rowNumber || 308 <= rowNumber)) {
				/** @type {number} */
				x = x >> 2 << 2;
				/** @type {number} */
				rowNumber = rowNumber >> 2 << 2;
				/** @type {number} */
				index = 400 * (rowNumber - 8) + (x - 8);
				/** @type {number} */
				parts[index] = 18;
				/** @type {number} */
				ret[index] = 0;
			}
		} else {
			if (rows[i] == tr) {
				x = parseInt(vertices[index].x);
				rowNumber = parseInt(vertices[index].y);
				if (!(8 > x || length - 8 <= x || 8 > rowNumber || 308 <= rowNumber)) {
					/** @type {number} */
					x = x >> 2 << 2;
					/** @type {number} */
					rowNumber = rowNumber >> 2 << 2;
					/** @type {number} */
					index = 400 * (rowNumber - 8) + (x - 8);
					/** @type {number} */
					parts[index] = 22;
					ret[index] = list[i];
				}
			} else {
				if (rows[i] == float) {
					x = parseInt(vertices[index + 4].x);
					rowNumber = parseInt(vertices[index + 4].y);
					if (!(8 > x || length - 8 <= x || 8 > rowNumber || 308 <= rowNumber)) {
						/** @type {number} */
						x = x >> 2 << 2;
						/** @type {number} */
						rowNumber = rowNumber >> 2 << 2;
						/** @type {number} */
						index = 400 * (rowNumber - 8) + (x - 8);
						/** @type {number} */
						parts[index] = 30;
						ret[index] = list[i];
					}
				} else {
					if (rows[i] == auto) {
						x = parseInt(vertices[index].x);
						rowNumber = parseInt(vertices[index].y);
						if (!(8 > x || length - 8 <= x || 8 > rowNumber || 308 <= rowNumber)) {
							/** @type {number} */
							x = x >> 2 << 2;
							/** @type {number} */
							rowNumber = rowNumber >> 2 << 2;
							/** @type {number} */
							index = 400 * (rowNumber - 8) + (x - 8);
							/** @type {number} */
							parts[index] = 22;
							/** @type {number} */
							ret[index] = 10;
						}
					}
				}
			}
		}
	}
	/** @type {number} */
	i = 0;
	for (; i < _len; i++) {
		if (0 != plugins[i]) {
			x = parseInt(objects[i].x);
			rowNumber = parseInt(objects[i].y);
			if (!(8 > x || length - 8 <= x || 8 > rowNumber || 308 <= rowNumber)) {
				/** @type {number} */
				index = 400 * (rowNumber - 8) + (x - 8);
				if (0 == parts[index]) {
					/** @type {number} */
					parts[index] = 40;
					ret[index] = data[i];
				}
			}
		}
	}
	zoom = z;
}
/**
 * @return {undefined}
 */
function html() {
	var j;
	var d;
	var n;
	var i;
	/** @type {!Array} */
	d = Array(12E4);
	/** @type {number} */
	n = 0;
	var o;
	/** @type {number} */
	j = 0;
	for (; 12E4 > j; j++) {
		if (i = parts[j], o = 1, i == id || i == all || 22 == i || 40 == i) {
			d[n++] = i;
			d[n++] = ret[j];
		} else {
			if (30 == i) {
				/** @type {number} */
				d[n++] = 32;
				d[n++] = ret[j];
			} else {
				for (; 119999 > j && i == parts[j + 1]; j++) {
					if (o++, 255 == o) {
						j++;
						break;
					}
				}
				d[n++] = i;
				if (1 != o) {
					if (16 > o) {
						/** @type {number} */
						d[n++] = 48 + o;
					} else {
						/** @type {number} */
						d[n++] = 48 + (o & 15);
						/** @type {number} */
						d[n++] = 48 + (o >> 4);
					}
				}
			}
		}
	}
	/** @type {!Array<string>} */
	o = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz.*".split("");
	/** @type {!Array} */
	var a = Array(2 * n);
	/** @type {number} */
	var cnt = 0;
	/** @type {string} */
	a[cnt++] = "1";
	/** @type {string} */
	a[cnt++] = "0";
	/** @type {string} */
	a[cnt++] = "0123456789:;ABCDEF".split("")[i1 + 1];
	a[cnt++] = "" + max;
	a[cnt++] = "" + err;
	a[cnt++] = "" + type;
	a[cnt++] = "" + option;
	/** @type {string} */
	a[cnt++] = "0";
	/** @type {string} */
	a[cnt++] = o[zoom & 63];
	/** @type {string} */
	a[cnt++] = o[zoom >> 6];
	/** @type {string} */
	a[cnt++] = "0";
	/** @type {string} */
	a[cnt++] = "0";
	/** @type {string} */
	a[cnt++] = "0";
	/** @type {string} */
	a[cnt++] = "0";
	/** @type {string} */
	a[cnt++] = "0";
	/** @type {string} */
	a[cnt++] = "0";
	/** @type {!Array} */
	var result = Array(4096);
	/** @type {number} */
	j = 0;
	for (; 4096 > j; j++) {
		/** @type {!Array} */
		result[j] = [];
	}
	/** @type {number} */
	var x = 1;
	/** @type {number} */
	j = 0;
	for (; j < n;) {
		/** @type {number} */
		var validationVM = 0;
		/** @type {number} */
		var y = 1;
		/** @type {number} */
		var v = 1;
		for (; v < x; v++) {
			if (result[v].length == y) {
				/** @type {number} */
				i = 0;
				for (; i < y && result[v][i] == d[j + i]; i++) {
				}
				if (i == y && (validationVM = v, y++, j + y >= n)) {
					break;
				}
			}
		}
		/** @type {string} */
		a[cnt++] = o[validationVM >> 6];
		/** @type {string} */
		a[cnt++] = o[validationVM & 63];
		/** @type {string} */
		a[cnt++] = o[d[j + y - 1]];
		if (4096 > x) {
			/** @type {!Array} */
			result[x] = Array(y);
			/** @type {number} */
			i = 0;
			for (; i < y; i++) {
				result[x][i] = d[j + i];
			}
			x++;
		}
		/** @type {number} */
		j = j + y;
	}
	if (!a[cnt - 1]) {
		/** @type {string} */
		a[cnt - 1] = o[0];
	}
	/** @type {string} */
	s = "";
	/** @type {number} */
	j = 0;
	for (; j < cnt; j++) {
		/** @type {string} */
		s = s + a[j];
	}
	/** @type {!Array} */
	a = Array(7500);
	/** @type {number} */
	n = j = 0;
	for (; 300 > n; n = n + 4) {
		/** @type {number} */
		d = 0;
		for (; 400 > d; d = d + 4) {
			/** @type {number} */
			i = 400 * n + d;
			if (0 == parts[i]) {
				/** @type {number} */
				i = i + 401;
			}
			if (11 == i1) {
				if (parts[i] == options || parts[i] == object || parts[i] == elem || parts[i] == end || parts[i] == title || parts[i] == event) {
					/** @type {string} */
					a[j++] = o[parts[i]];
				} else {
					/** @type {string} */
					a[j++] = "0";
				}
			} else {
				if (13 == i1) {
					/** @type {string} */
					a[j++] = 0 == parts[i] ? "0" : "1";
				} else {
					/** @type {string} */
					a[j++] = o[parts[i]];
				}
			}
		}
	}
	/** @type {string} */
	sum = "";
	/** @type {number} */
	j = 0;
	for (; 7500 > j; j++) {
		/** @type {string} */
		sum = sum + a[j];
	}
	/** @type {!Array<string>} */
	i = "0123456789abcdef".split("");
	if (9 == i1) {
		/** @type {!Array} */
		o = channels;
	} else {
		if (13 == i1) {
			/** @type {!Array} */
			o = [16777215, 0];
		} else {
			/** @type {!Array} */
			o = Array(settings.length);
			/** @type {number} */
			j = 0;
			for (; j < settings.length; j++) {
				o[j] = settings[j][0];
			}
		}
	}
	/** @type {string} */
	className = "";
	/** @type {number} */
	j = 0;
	for (; j < o.length; j++) {
		/** @type {string} */
		className = className + i[o[j] >> 20 & 15];
		/** @type {string} */
		className = className + i[o[j] >> 16 & 15];
		/** @type {string} */
		className = className + i[o[j] >> 12 & 15];
		/** @type {string} */
		className = className + i[o[j] >> 8 & 15];
		/** @type {string} */
		className = className + i[o[j] >> 4 & 15];
		/** @type {string} */
		className = className + i[o[j] & 15];
	}
}
/**
 * @return {undefined}
 */
function error() {
	var i;
	var j;
	/** @type {!Array} */
	var a = Array(24E4);
	var y = s.length;
	/** @type {!Array} */
	var data = Array(12E4);
	/** @type {number} */
	var offset = 0;
	/** @type {number} */
	i = 0;
	for (; i < s.length; i++) {
		a[i] = s[i];
	}
	/** @type {!Array} */
	var arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 0, 0, 0, 62, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 0, 0, 0, 0, 0, 0, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0, 0, 0, 0, 0];
	/** @type {number} */
	j = ~~a[0];
	/** @type {!Array<string>} */
	var ret = "0123456789:;ABCDEF".split("");
	/** @type {number} */
	i = 0;
	for (; i < ret.length && a[2] != ret[i]; i++) {
	}
	/** @type {number} */
	i1 = i - 1;
	if (-1 == i1) {
		/** @type {number} */
		i1 = 2;
	}
	/** @type {number} */
	max = ~~a[3];
	/** @type {number} */
	err = ~~a[4];
	/** @type {number} */
	type = ~~a[5];
	/** @type {number} */
	option = ~~a[6];
	if (0 == j) {
		/** @type {number} */
		zoom = 100;
	}
	if (1 <= j) {
		zoom = arr[a[8].charCodeAt(0)];
		zoom = zoom + (arr[a[9].charCodeAt(0)] << 6);
	}
	/** @type {!Array} */
	ret = Array(4096);
	/** @type {number} */
	i = 0;
	for (; 4096 > i; i++) {
		/** @type {!Array} */
		ret[i] = [];
	}
	/** @type {number} */
	var name = 1;
	/** @type {number} */
	i = 0 == j ? 8 : 16;
	for (; i < y;) {
		/** @type {number} */
		var current = 0;
		/** @type {number} */
		var n = 1;
		/** @type {number} */
		current = arr[a[i].charCodeAt(0)] << 6;
		i++;
		current = current + arr[a[i].charCodeAt(0)];
		i++;
		j = i < y ? arr[a[i].charCodeAt(0)] : 0;
		i++;
		if (0 < current) {
			/** @type {number} */
			var j = 0;
			for (; j < ret[current].length; j++) {
				data[offset++] = ret[current][j];
			}
			n = 1 + ret[current].length;
		}
		data[offset++] = j;
		if (4096 > name) {
			/** @type {!Array} */
			ret[name] = Array(n);
			/** @type {number} */
			j = 0;
			for (; j < n; j++) {
				ret[name][j] = data[offset - n + j];
			}
			name++;
		}
	}
	/** @type {number} */
	data[offset++] = 0;
	/** @type {number} */
	i = j = data[offset++] = 0;
	for (; 12E4 > j;) {
		if (a = data[i++], a == id || a == all || 22 == a || 40 == a) {
			parts[j] = a;
			ret[j] = data[i++];
			j++;
		} else {
			if (32 == a) {
				/** @type {number} */
				parts[j] = 30;
				ret[j] = data[i++];
				j++;
			} else {
				if (48 > data[i]) {
					parts[j] = a;
					j++;
				} else {
					if (48 > data[i + 1]) {
						/** @type {number} */
						n = data[i++] - 48;
					} else {
						/** @type {number} */
						n = data[i++] - 48;
						/** @type {number} */
						n = n + (data[i++] - 48 << 4);
					}
					/** @type {number} */
					j = 0;
					for (; j < n; j++) {
						parts[j++] = a;
					}
				}
			}
		}
	}
}
/**
 * @return {undefined}
 */
function update() {
	var key;
	var s;
	var value;
	var i;
	/** @type {number} */
	var beginSize = 0;
	mockObject.e(1);
	/** @type {number} */
	value = 0;
	for (; 300 > value; value++) {
		/** @type {number} */
		s = 0;
		for (; 400 > s; s++) {
			/** @type {number} */
			i = 400 * value + s;
			if (0 == parts[i]) {
				/** @type {number} */
				i = (value + 8) * length + (s + 8);
				/** @type {number} */
				obj[i] = element;
			} else {
				if (1 == parts[i]) {
					/** @type {number} */
					i = ((value >> 2) + 2) * step + ((s >> 2) + 2);
					/** @type {number} */
					out[i] = 1;
					/** @type {number} */
					i = (value + 8) * length + (s + 8);
					/** @type {number} */
					obj[i] = -1;
				} else {
					if (9 == parts[i]) {
						check(s + 8, value + 8);
					} else {
						if (18 == parts[i]) {
							log(s + 8, value + 8, 0, 0);
						} else {
							if (22 == parts[i]) {
								log(s + 8, value + 8, 22, ret[i]);
							} else {
								if (30 == parts[i]) {
									log(s + 8, value + 8, 32, ret[i]);
								} else {
									if (40 == parts[i]) {
										func(s + 8, value + 8, ret[i]);
									} else {
										beginSize++;
										if (0 >= max && beginSize > beginHint[0]) {
											/** @type {number} */
											max = 1;
										}
										if (1 >= max && beginSize > beginHint[1]) {
											/** @type {number} */
											max = 2;
										}
										key = callback(s + 8, value + 8, parts[i]);
										if (parts[i] == id) {
											/** @type {number} */
											items[key].x = 0.1 * Math.cos(ret[i] * ratio / 32);
											/** @type {number} */
											items[key].y = 0.1 * -Math.sin(ret[i] * ratio / 32);
											/** @type {number} */
											obj[(value + 8) * length + (s + 8)] = temp;
										} else {
											if (parts[i] == all) {
												arr[key] = ret[i];
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	s = new Vector;
	/** @type {number} */
	key = 0;
	for (; key < k; key++) {
		i = parseInt(Math.random() * k);
		s.set(params[key]);
		params[key].set(params[i]);
		params[i].set(s);
		s.set(items[key]);
		items[key].set(items[i]);
		items[i].set(s);
		/** @type {number} */
		value = args[key];
		/** @type {number} */
		args[key] = args[i];
		/** @type {number} */
		args[i] = value;
		/** @type {number} */
		value = arr[key];
		/** @type {number} */
		arr[key] = arr[i];
		/** @type {number} */
		arr[i] = value;
		/** @type {number} */
		value = map[key];
		/** @type {number} */
		map[key] = map[i];
		/** @type {number} */
		map[i] = value;
		/** @type {number} */
		value = result[key];
		/** @type {number} */
		result[key] = result[i];
		/** @type {number} */
		result[i] = value;
		/** @type {number} */
		obj[result[key]] = args[key] == id ? temp : key;
		obj[result[i]] = args[i] == id ? temp : i;
	}
	z = zoom;
}
/**
 * @param {?} html
 * @param {number} i
 * @param {number} s
 * @param {number} type
 * @param {number} name
 * @return {undefined}
 */
function format(html, i, s, type, name) {
	/** @type {number} */
	var j = i;
	for (;;) {
		if (0 <= obj[j] && args[obj[j]] == s) {
			/** @type {number} */
			args[obj[j]] = type;
			/** @type {number} */
			arr[obj[j]] = name;
			/** @type {number} */
			map[obj[j]] = 0;
			j--;
		} else {
			break;
		}
	}
	j++;
	var k = i + 1;
	for (;;) {
		if (0 <= obj[k] && args[obj[k]] == s) {
			/** @type {number} */
			args[obj[k]] = type;
			/** @type {number} */
			arr[obj[k]] = name;
			/** @type {number} */
			map[obj[k]] = 0;
			k++;
		} else {
			break;
		}
	}
	k--;
	i = j;
	for (; i <= k; i++) {
		if (0 <= obj[i - length] && args[obj[i - length]] == s) {
			format(html, i - length, s, type, name);
		}
		if (0 <= obj[i + length] && args[obj[i + length]] == s) {
			format(html, i + length, s, type, name);
		}
	}
}
/**
 * @param {?} output
 * @param {number} string
 * @return {undefined}
 */
function transform(output, string) {
	var i;
	var start;
	var key;
	var t;
	var x;
	i = new Vector;
	var j = 0 == string ? url : l;
	var n = 0 == string ? hasToggledVideo : hasToggledAudio;
	t = 0 == string ? rx : ry;
	var r = 0 == string ? target : cmp;
	if (34 > j) {
		if (1 == bx1 && (r = 0 == string ? rx : ry), r && (n = value - total, r = y - g, !(1 >= w && 1 == gasSum && 1 >= tileSize && 0 == n && 0 == r && 3 != bx1))) {
			var m = max(max(abs(n), abs(r)), 1);
			n = parseInt((n << 8) / m);
			r = parseInt((r << 8) / m);
			/** @type {number} */
			var s = (total << 8) + 127;
			/** @type {number} */
			var sumred = (g << 8) + 127;
			/** @type {number} */
			start = 0;
			for (; start <= m; start++, s = s + n, sumred = sumred + r) {
				var c = w + 0;
				/** @type {number} */
				var i = (s >> 8) - c;
				/** @type {number} */
				t = (sumred >> 8) - c;
				/** @type {number} */
				var j = i + 2 * c;
				/** @type {number} */
				var end = t + 2 * c;
				if (8 > i) {
					/** @type {number} */
					i = 8;
				}
				if (8 > t) {
					/** @type {number} */
					t = 8;
				}
				if (j > length - 8 - 1) {
					/** @type {number} */
					j = length - 8 - 1;
				}
				if (307 < end) {
					/** @type {number} */
					end = 307;
				}
				/** @type {number} */
				var index = t * length + i;
				/** @type {number} */
				var delta = length - (j - i + 1);
				/** @type {number} */
				x = t;
				for (; x <= end; x++, index = index + delta) {
					/** @type {number} */
					t = i;
					for (; t <= j; t++, index++) {
						if (!(c * c + 1 < (t - (s >> 8)) * (t - (s >> 8)) + (x - (sumred >> 8)) * (x - (sumred >> 8)))) {
							if (3 == bx1) {
								key = 0 != types[j] ? types[j] : _;
								/** @type {number} */
								var i = 0;
								if (key != id) {
									if (key == all) {
										i = 0 != theCache[url] ? theCache[url] : 0 != theCache[l] ? theCache[l] : _;
									} else {
										if (key == title) {
											/** @type {number} */
											i = 8 * angle(expected) / firstX + 0.5;
											if (8 <= i) {
												/** @type {number} */
												i = 0;
											}
											i = parseInt(i) + 1;
										}
									}
									if (0 <= obj[index] && args[obj[index]] != key) {
										format(output, index, args[obj[index]], key, i);
									}
								}
							} else {
								if (obj[index] == element) {
									i = types[j];
									if ((0 == string && cmp && 34 > l || 1 == string && target && 34 > url) && 50 > apply(100)) {
										i = types[0 == string ? l : url];
									}
									key = callback(t, x, i);
									if (!(0 > key)) {
										if (i == id) {
											push(i, expected, 0.1);
											items[key].set(i);
											/** @type {number} */
											obj[index] = temp;
										} else {
											if (i == all) {
												arr[key] = 0 != theCache[url] ? theCache[url] : 0 != theCache[l] ? theCache[l] : _;
											} else {
												if (i == title) {
													/** @type {number} */
													i = 8 * angle(expected) / firstX + 0.5;
													if (8 <= i) {
														/** @type {number} */
														i = 0;
													}
													arr[key] = parseInt(i) + 1;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	} else {
		if (40 == j) {
			/** @type {number} */
			key = (y >> 2) * step + (value >> 2);
			push(i, expected, 10);
			if (r && 0 == out[key]) {
				values[key].add(i);
				if (10 < expect(values[key]) && 1 == gasSum) {
					get(values[key]);
					parse(values[key], 10);
				}
			}
		} else {
			if (41 == j) {
				/** @type {number} */
				key = (y >> 2) * step + (value >> 2);
				if (r) {
					/** @type {number} */
					c = (w + 1) * (w + 1) * 0.25;
					/** @type {number} */
					c = 0 == string ? c : -c;
					if (0 == out[key]) {
						buf[key] += c;
						/** @type {number} */
						t = t - c;
					}
					if (0 == out[key - 1]) {
						buf[key - 1] += c;
						/** @type {number} */
						t = t - c;
					}
					if (0 == out[key - step]) {
						buf[key - step] += c;
						/** @type {number} */
						t = t - c;
					}
					if (0 == out[key - step - 1]) {
						buf[key - step - 1] += c;
						/** @type {number} */
						t = t - c;
					}
				}
			} else {
				if (43 == j) {
					if (!(m > model - 5)) {
						if (t = value >> 2 << 2, x = y >> 2 << 2, key = (y >> 2) * step + (value >> 2), 0 != out[key]) {
							content++;
						} else {
							if (n && content++, r) {
								/** @type {number} */
								j = 0;
								/** @type {number} */
								n = m - 1;
								for (; 0 <= n && o[n] == content; n--) {
									j++;
								}
								if (5 > j) {
									content++;
									pick(t + parseInt(apply(width)), x + parseInt(apply(width)));
									pick(t + parseInt(apply(width)), x + parseInt(apply(width)));
									pick(t + parseInt(apply(width)), x + parseInt(apply(width)));
									pick(t + parseInt(apply(width)), x + parseInt(apply(width)));
								}
								pick(t + parseInt(apply(width)), x + parseInt(apply(width)));
							}
						}
					}
				} else {
					if (44 == j) {
						if (n) {
							t = clamp(value, 24, 391);
							x = clamp(y, 24, 291);
							/** @type {number} */
							i = j = 0;
							for (; i < idx; i++) {
								if (t == times[i] && x == tokens[i]) {
									/** @type {number} */
									j = 1;
									break;
								}
							}
							if (0 == j) {
								check(t, x);
							}
						}
					} else {
						if (45 == j || 46 == j || 47 == j || 49 == j) {
							/** @type {number} */
							t = value >> 2 << 2;
							/** @type {number} */
							x = y >> 2 << 2;
							/** @type {number} */
							key = (y >> 2) * step + (value >> 2);
							if (0 == out[key]) {
								if (n && 46 == j) {
									log(t, x, 0, 0);
								} else {
									if (n && 47 == j) {
										log(t, x, 22, w);
									} else {
										if (n && 45 == j) {
											i = 0 != utilReqPaths[url] ? utilReqPaths[url] : 0 != utilReqPaths[l] ? utilReqPaths[l] : 0;
											log(t, x, 30, i);
										} else {
											if (n && 49 == j) {
												log(t, x, 22, 10);
											}
										}
									}
								}
							}
						} else {
							if (48 == j) {
								/** @type {number} */
								key = (y >> 2) * step + (value >> 2);
								if (0 == out[key] && n && 48 == j) {
									i = 0 != assetLocationTranslation[url] ? assetLocationTranslation[url] : 0 != assetLocationTranslation[l] ? assetLocationTranslation[l] : _;
									func(value, y, i);
								}
							} else {
								if (54 == j) {
									a = value;
									/** @type {number} */
									d = y - 14;
									if (n) {
										/** @type {number} */
										evalID = 20;
									}
								} else {
									if (50 == j || 51 == j || 52 == j) {
										if (1 == bx1 && (r = 0 == string ? rx : ry), r) {
											/** @type {number} */
											n = parseInt(value / width) - parseInt(total / width);
											/** @type {number} */
											r = parseInt(y / width) - parseInt(g / width);
											m = max(max(abs(n), abs(r)), 1);
											n = parseInt((n << 8) / m);
											r = parseInt((r << 8) / m);
											/** @type {number} */
											s = (parseInt(total / width) << 8) - 127;
											/** @type {number} */
											sumred = (parseInt(g / width) << 8) - 127;
											/** @type {number} */
											i = 0;
											for (; i <= m; i++, s = s + n, sumred = sumred + r) {
												/** @type {number} */
												start = (s >> 8) - parseInt(w / 2);
												/** @type {number} */
												c = (sumred >> 8) - parseInt(w / 2);
												/** @type {number} */
												i = start + w / 2 + 0.5;
												/** @type {number} */
												j = c + w / 2 + 0.5;
												/** @type {number} */
												x = c;
												for (; x <= c + w; x++) {
													/** @type {number} */
													t = start;
													for (; t <= start + w; t++) {
														if (!((t - i) * (t - i) + (x - j) * (x - j) > w * w / 4)) {
															key = clamp(x, 2, cols - 3) * step + clamp(t, 2, step - 3);
															if (50 == j) {
																/** @type {number} */
																out[key] = 1;
																cb(values[key], 0, 0);
																t = t + buf[key];
																/** @type {number} */
																buf[key] = 0;
															} else {
																if (51 == j) {
																	/** @type {number} */
																	out[key] = -2;
																} else {
																	if (52 == j && 0 == out[key]) {
																		/** @type {number} */
																		out[key] = -2;
																		cb(values[key], 0, 0);
																		t = t + buf[key];
																		/** @type {number} */
																		buf[key] = 0;
																	}
																}
															}
														}
													}
												}
											}
											if (52 == j && 0 == w) {
												/** @type {number} */
												n = value - total;
												/** @type {number} */
												r = y - g;
												m = max(max(abs(n), abs(r)), 1);
												n = parseInt((n << 8) / m);
												r = parseInt((r << 8) / m);
												/** @type {number} */
												s = (total << 8) + 127;
												/** @type {number} */
												sumred = (g << 8) + 127;
												/** @type {number} */
												i = 0;
												for (; i <= m; i++, s = s + n, sumred = sumred + r) {
													/** @type {number} */
													key = 0;
													for (; key < k; key++) {
														if (s >> 8 == parseInt(params[key].x) && sumred >> 8 == parseInt(params[key].y)) {
															call(key--);
														}
													}
												}
											}
											if (50 == j || 52 == j) {
												/** @type {number} */
												i = 0;
												for (; i < k; i++) {
													/** @type {number} */
													key = (parseInt(params[i].y) >> 2) * step + (parseInt(params[i].x) >> 2);
													if (0 != out[key]) {
														call(i--);
													}
												}
											}
											if (51 == j) {
												/** @type {number} */
												i = 0;
												for (; i < idx; i++) {
													if (key = (parseInt(tokens[i]) >> 2) * step + (parseInt(times[i]) >> 2), -2 == out[key] && (t = i--, 0 != idx)) {
														r = n = x = void 0;
														/** @type {number} */
														x = (tokens[t] - 16) * length + (times[t] - 16);
														/** @type {number} */
														r = 0;
														for (; 32 > r; r++, x = x + (length - 32)) {
															/** @type {number} */
															n = 0;
															for (; 32 > n; n++, x++) {
																if (-3 == obj[x]) {
																	/** @type {number} */
																	obj[x] = element;
																}
															}
														}
														times[t] = times[idx - 1];
														tokens[t] = tokens[idx - 1];
														rules[t] = rules[idx - 1];
														words[t] = words[idx - 1];
														idx--;
													}
												}
											}
											if (50 == j || 51 == j) {
												/** @type {number} */
												i = 0;
												for (; i < to; i++) {
													if (rows[i] == item || rows[i] == item + 1 || rows[i] == float || rows[i] == auto) {
														/** @type {number} */
														start = 4;
														for (; 6 > start; start++) {
															if (key = (parseInt(vertices[i * stride + start].y) >> 2) * step + (parseInt(vertices[i * stride + start].x) >> 2), 0 != out[key]) {
																split(i--);
																break;
															}
														}
													} else {
														if (rows[i] == tr) {
															/** @type {number} */
															start = 0;
															for (; 4 > start; start++) {
																if (key = (parseInt(vertices[i * stride + start].y) >> 2) * step + (parseInt(vertices[i * stride + start].x) >> 2), 0 != out[key]) {
																	split(i--);
																	break;
																}
															}
														}
													}
												}
												/** @type {number} */
												i = 0;
												for (; i < _len; i++) {
													if (0 != plugins[i] && (key = (parseInt(objects[i].y) >> 2) * step + (parseInt(objects[i].x) >> 2), 0 != out[key])) {
														key = parseInt(objects[i].y) * length + parseInt(objects[i].x);
														/** @type {number} */
														start = 0;
														for (; 21 > start; start++) {
															if (-2 == obj[key + attrs[start]]) {
																/** @type {number} */
																obj[key + attrs[start]] = element;
															}
														}
														/** @type {number} */
														plugins[i] = 0;
													}
												}
											}
											if (51 == j || 52 == j) {
												/** @type {number} */
												i = 0;
												for (; i < len; i++) {
													if (-2 == out[i]) {
														/** @type {number} */
														out[i] = 0;
													}
												}
											}
											/** @type {number} */
											key = 8 * length + 8;
											/** @type {number} */
											x = 8;
											for (; 308 > x; x++, key = key + 16) {
												/** @type {number} */
												t = 8;
												for (; 408 > t; t++, key++) {
													/** @type {number} */
													index = (x >> 2) * step + (t >> 2);
													if (0 == out[index] && -1 == obj[key]) {
														/** @type {number} */
														obj[key] = element;
													} else {
														if (1 == out[index] && -1 > obj[key]) {
															/** @type {number} */
															obj[key] = -1;
														}
													}
												}
											}
										}
									} else {
										if (53 == j) {
											if (n) {
												if (0 == COLON) {
													y1 = y2 = value;
													c = b = y;
												} else {
													if (!(1 == gasSum && 1 >= tileSize && y1 == y2 && c == b)) {
														if (y1 > y2) {
															t = y1;
															y1 = y2;
															y2 = t;
														}
														if (c > b) {
															x = c;
															c = b;
															b = x;
														}
														/** @type {number} */
														r = value - parseInt((y2 - y1) / 2) - y1;
														/** @type {number} */
														m = y - parseInt((b - c) / 2) - c;
														/** @type {number} */
														x = c - 8;
														for (; x <= b - 8; x++) {
															if (!(0 > x + m || 300 <= x + m)) {
																/** @type {number} */
																t = y1 - 8;
																for (; t <= y2 - 8; t++) {
																	if (!(0 > t + r || 400 <= t + r)) {
																		/** @type {number} */
																		n = 400 * x + t;
																		if (0 != results[n] && obj[(m + x + 8) * length + (r + t + 8)] == element) {
																			j = callback(r + t + 8, m + x + 8, results[n]);
																			if (0 <= j) {
																				if (results[n] == id) {
																					/** @type {number} */
																					items[j].x = 0.1 * Math.cos(state[n] * ratio / 32);
																					/** @type {number} */
																					items[j].y = 0.1 * -Math.sin(state[n] * ratio / 32);
																					/** @type {number} */
																					obj[(m + x + 8) * length + (r + t + 8)] = temp;
																				} else {
																					if (results[n] == all) {
																						arr[j] = state[n];
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											} else {
												if (t && 0 == COLON) {
													/** @type {number} */
													j = 0;
													for (; 12E4 > j; j++) {
														/** @type {number} */
														results[j] = 0;
														/** @type {number} */
														state[j] = 0;
													}
													/** @type {number} */
													j = 0;
													for (; j < k; j++) {
														t = parseInt(params[j].x);
														x = parseInt(params[j].y);
														if (!(8 > t || 408 <= t || 8 > x || 308 <= x)) {
															/** @type {number} */
															t = t - 8;
															/** @type {number} */
															x = x - 8;
															t = 400 * x + t;
															/** @type {number} */
															results[t] = args[j];
															if (args[j] == id) {
																state[t] = fn(parseInt(64 * angle(items[j]) / firstX), 63);
															} else {
																if (args[j] == all) {
																	/** @type {number} */
																	state[t] = arr[j] % 100;
																}
															}
														}
													}
												} else {
													if (r && 0 == COLON) {
														y2 = value;
														b = y;
													}
												}
											}
										} else {
											if (57 == j && 0 != tileSize && r) {
												/** @type {number} */
												time = time - (lat - lastLat) / (1 << tileSize);
												/** @type {number} */
												delta = delta - (lon - lastLon) / (1 << tileSize);
												time = clamp(time, 0, 400 - (400 >> tileSize));
												delta = clamp(delta, 0, 300 - [300, 150, 75, 38, 19][tileSize]);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
/**
 * @param {number} s
 * @param {number} value
 * @param {number} key
 * @return {?}
 */
function callback(s, value, key) {
	if (k >= beginHint[max] || 7 > s || 409 <= s || 7 > value || 309 <= value) {
		return -1;
	}
	cb(params[k], s, value);
	cb(items[k], 0, 0);
	/** @type {number} */
	args[k] = key;
	/** @type {number} */
	arr[k] = 0;
	/** @type {number} */
	map[k] = 0;
	/** @type {number} */
	samples[k] = 0;
	/** @type {number} */
	result[k] = ~~value * length + ~~s;
	obj[result[k]] = k;
	k++;
	return k - 1;
}
/**
 * @param {number} i
 * @return {undefined}
 */
function call(i) {
	if (0 != k) {
		/** @type {number} */
		obj[result[i]] = element;
		k--;
		if (k != i) {
			params[i].set(params[k]);
			items[i].set(items[k]);
			/** @type {number} */
			args[i] = args[k];
			/** @type {number} */
			arr[i] = arr[k];
			/** @type {number} */
			map[i] = map[k];
			/** @type {number} */
			samples[i] = samples[k];
			/** @type {number} */
			result[i] = result[k];
			obj[result[i]] = args[i] == id ? temp : i;
		}
	}
}
/**
 * @param {number} index
 * @param {number} name
 * @param {number} k
 * @param {number} key
 * @return {undefined}
 */
function iterator(index, name, k, key) {
	var temp;
	temp = params[index].x;
	params[index].x = params[name].x;
	params[name].x = temp;
	temp = params[index].y;
	params[index].y = params[name].y;
	params[name].y = temp;
	/** @type {number} */
	temp = obj[k];
	/** @type {number} */
	obj[k] = obj[key];
	/** @type {number} */
	obj[key] = temp;
	/** @type {number} */
	temp = result[index];
	/** @type {number} */
	result[index] = result[name];
	/** @type {number} */
	result[name] = temp;
}
/**
 * @param {number} key
 * @param {!Object} item
 * @return {?}
 */
function done(key, item) {
	parse(item, 3.8 / (expect(item) + 1));
	/** @type {number} */
	var i = (params[key].y >> 0) * length + (params[key].x + item.x >> 0);
	if (obj[i] <= temp) {
		params[key].x += item.x;
	}
	/** @type {number} */
	i = (params[key].y + item.y >> 0) * length + (params[key].x >> 0);
	if (obj[i] <= temp) {
		params[key].y += item.y;
	}
	/** @type {number} */
	result[key] = (params[key].y >> 0) * length + (params[key].x >> 0);
	/** @type {number} */
	obj[result[key]] = key;
	return result[key];
}
/**
 * @param {number} time
 * @param {number} value
 * @return {undefined}
 */
function check(time, value) {
	if (idx != selector) {
		/** @type {number} */
		times[idx] = time;
		/** @type {number} */
		tokens[idx] = value;
		/** @type {number} */
		rules[idx] = 0.5;
		/** @type {number} */
		words[idx] = 0;
		idx++;
	}
}
/**
 * @param {number} v
 * @param {number} i
 * @return {undefined}
 */
function pick(v, i) {
	if (m != model) {
		/** @type {number} */
		array[m] = v;
		/** @type {number} */
		pos[m] = i;
		o[m] = content;
		/** @type {number} */
		colors[m] = 0;
		m++;
	}
}
/**
 * @param {number} j
 * @param {number} i
 * @return {undefined}
 */
function find(j, i) {
	var col = ticksPerBeat;
	var a = new Vector;
	/** @type {number} */
	a.x = array[i] - array[j];
	/** @type {number} */
	a.y = pos[i] - pos[j];
	var c = get(a);
	if (0 != c) {
		/** @type {number} */
		c = col - c;
		array[j] -= a.x * c * 0.5;
		pos[j] -= a.y * c * 0.5;
		array[i] += a.x * c * 0.5;
		pos[i] += a.y * c * 0.5;
	}
}
/**
 * @param {number} start
 * @param {number} f
 * @param {number} a
 * @param {number} b
 * @param {number} limit
 * @return {undefined}
 */
function compare(start, f, a, b, limit) {
	/** @type {number} */
	a = a - start;
	/** @type {number} */
	b = b - f;
	var to;
	if (abs(a) >= abs(b)) {
		to = parseInt(abs(a));
		if (0 != a) {
			/** @type {number} */
			b = b / abs(a);
		}
		/** @type {number} */
		a = 0 <= a ? 1 : -1;
	} else {
		to = parseInt(abs(b));
		if (0 != b) {
			/** @type {number} */
			a = a / abs(b);
		}
		/** @type {number} */
		b = 0 <= b ? 1 : -1;
	}
	start = start + 0.5;
	f = f + 0.5;
	/** @type {number} */
	var idx = 0;
	for (; idx <= to; idx++, start = start + a, f = f + b) {
		if (!(8 > start || 408 <= start || 8 > f || 308 <= f)) {
			if (obj[parseInt(f) * length + parseInt(start)] <= temp) {
				callback(parseInt(start), parseInt(f), limit);
			}
		}
	}
}
/**
 * @param {number} x
 * @param {number} a
 * @param {number} b
 * @param {number} v
 * @return {undefined}
 */
function log(x, a, b, v) {
	if (to != from) {
		var i;
		var index;
		/** @type {number} */
		var g = 0;
		/** @type {number} */
		var newPiece = 0;
		/** @type {number} */
		var from = 0;
		if (30 == b || 32 == b) {
			/** @type {number} */
			i = 0;
			for (; i < to; i++) {
				if (rows[i] == float) {
					g++;
					/** @type {number} */
					newPiece = 1 - g_board[i];
					/** @type {number} */
					from = i;
				}
			}
			if (2 <= g || 0 != v && 0 == props[v]) {
				return;
			}
		}
		/** @type {number} */
		index = to * stride;
		/** @type {number} */
		i = 0;
		for (; 20 > i; i++) {
			cb(vertices[index + i], x + apply(4), a + apply(4));
			row[index + i].set(vertices[index + i]);
		}
		/** @type {number} */
		i = 0;
		for (; i < stride; i++) {
			/** @type {number} */
			keys[index + i] = 0;
		}
		cb(messages[to], 0, 0);
		/** @type {number} */
		rows[to] = item;
		/** @type {number} */
		children[to] = 0;
		/** @type {number} */
		lines[to] = 0;
		/** @type {number} */
		list[to] = v;
		/** @type {number} */
		g_board[to] = 0;
		if (22 == b) {
			if (10 == v) {
				/** @type {number} */
				rows[to] = auto;
				/** @type {number} */
				list[to] = 0;
				cb(vertices[index + 0], x, a);
				row[index + 0].set(vertices[index + 0]);
			} else {
				/** @type {number} */
				rows[to] = tr;
			}
		} else {
			if (30 == b) {
				/** @type {number} */
				rows[to] = float;
				/** @type {number} */
				g_board[to] = newPiece;
			} else {
				if (32 == b) {
					/** @type {number} */
					rows[to] = float;
					if (0 == g) {
						/** @type {number} */
						g_board[to] = 0;
					} else {
						/** @type {number} */
						b = parseInt(vertices[from * stride].x) >> 2 << 2;
						/** @type {number} */
						v = parseInt(vertices[from * stride].y) >> 2 << 2;
						if (x < b) {
							/** @type {number} */
							g_board[to] = 1;
							/** @type {number} */
							g_board[from] = 0;
						} else {
							if (x > b) {
								/** @type {number} */
								g_board[to] = 0;
								/** @type {number} */
								g_board[from] = 1;
							} else {
								if (a < v) {
									/** @type {number} */
									g_board[to] = 1;
									/** @type {number} */
									g_board[from] = 0;
								} else {
									/** @type {number} */
									g_board[to] = 0;
									/** @type {number} */
									g_board[from] = 1;
								}
							}
						}
					}
				}
			}
		}
		to++;
	}
}
/**
 * @param {number} i
 * @return {undefined}
 */
function split(i) {
	if (0 != to) {
		var j;
		var index;
		var key;
		/** @type {number} */
		index = i * stride;
		/** @type {number} */
		key = (to - 1) * stride;
		/** @type {number} */
		j = 0;
		for (; j < stride; j++, index++, key++) {
			vertices[index].set(vertices[key]);
			row[index].set(row[key]);
			keys[index] = keys[key];
		}
		messages[i].set(messages[to - 1]);
		rows[i] = rows[to - 1];
		children[i] = children[to - 1];
		lines[i] = lines[to - 1];
		list[i] = list[to - 1];
		g_board[i] = g_board[to - 1];
		to--;
	}
}
/**
 * @param {number} idx
 * @param {number} offset
 * @param {number} n
 * @return {undefined}
 */
function remove(idx, offset, n) {
	var data = new Vector;
	equals(data, vertices[idx], row[idx]);
	row[idx].set(vertices[idx]);
	data.y += offset;
	parse(data, n);
	vertices[idx].add(data);
}
/**
 * @param {number} key
 * @param {number} index
 * @param {number} r
 * @param {number} t
 * @param {number} f
 * @return {undefined}
 */
function verify(key, index, r, t, f) {
	var value = new Vector;
	equals(value, vertices[index], vertices[key]);
	var a = get(value);
	if (0 != a) {
		/** @type {number} */
		r = r - a;
		a = new Vector;
		push(a, value, r * t);
		vertices[key].sub(a);
		push(a, value, r * f);
		vertices[index].add(a);
	}
}
/**
 * @param {number} idx
 * @param {number} dir
 * @param {number} name
 * @param {number} moveTo
 * @return {undefined}
 */
function f(idx, dir, name, moveTo) {
	var d = new Vector;
	equals(d, vertices[idx], row[idx]);
	vertices[idx].set(row[idx]);
	if (0 != dir) {
		/** @type {number} */
		var i = (parseInt(vertices[idx].y) >> 2) * step + (parseInt(vertices[idx].x) >> 2);
		d.x += values[i].x * dir;
		d.y += values[i].y * dir;
	}
	if (0 == moveTo) {
		i = expect(d) + 1;
		if (8 <= i) {
			parse(d, 3.8 / i);
			/** @type {number} */
			dir = 2;
		} else {
			if (4 <= i) {
				parse(d, 0.5);
				/** @type {number} */
				dir = 2;
			} else {
				/** @type {number} */
				dir = 1;
			}
		}
	} else {
		dir = parseInt(expect(d) / 3) + 1;
		parse(d, 1 / dir);
	}
	/** @type {number} */
	keys[idx] = 0;
	if (1 == name) {
		parse(d, dir);
		vertices[idx].add(d);
		vertices[idx].x = clamp(vertices[idx].x, 4, length - 5);
		vertices[idx].y = clamp(vertices[idx].y, 4, 311);
	} else {
		/** @type {number} */
		moveTo = 0;
		for (; moveTo < dir; moveTo++) {
			name = vertices[idx].y + d.y;
			if (4 > name || 312 <= name) {
				/** @type {number} */
				keys[idx] = -5;
				break;
			}
			i = parseInt(name) * length + parseInt(vertices[idx].x);
			if (obj[i] <= temp) {
				/** @type {number} */
				vertices[idx].y = name;
			} else {
				if (-1 >= obj[i]) {
					d.x *= 0.5;
					/** @type {number} */
					d.y = -d.y;
					/** @type {number} */
					keys[idx] = obj[i];
				} else {
					d.x *= scales[args[obj[i]]];
					/** @type {number} */
					keys[idx] = args[obj[i]];
					if (0 > d.y) {
						/** @type {number} */
						vertices[idx].y = name;
					} else {
						if (2 == hash[args[obj[i]]] && args[obj[i]] != undefined) {
							/** @type {number} */
							vertices[idx].y = name;
						} else {
							/** @type {number} */
							d.y = -d.y;
						}
					}
				}
			}
			name = vertices[idx].x + d.x;
			if (4 > name || length - 4 <= name) {
				/** @type {number} */
				keys[idx] = -5;
				break;
			}
			i = parseInt(vertices[idx].y) * length + parseInt(name);
			if (obj[i] <= temp) {
				/** @type {number} */
				vertices[idx].x = name;
			} else {
				if (-1 >= obj[i]) {
					d.y *= 0.5;
					/** @type {number} */
					d.x = -d.x;
					/** @type {number} */
					keys[idx] = obj[i];
				} else {
					if (d.y *= scales[args[obj[i]]], d.x = -d.x, keys[idx] = args[obj[i]], 2 == hash[args[obj[i]]] || 6 == args[obj[i]]) {
						/** @type {number} */
						vertices[idx].x = name;
					}
				}
			}
		}
	}
}
/**
 * @param {number} pos
 * @param {number} value
 * @return {?}
 */
function label(pos, value) {
	/** @type {number} */
	var val = 0;
	/** @type {number} */
	var i = pos;
	for (; i < value; i++) {
		if (-5 == keys[i]) {
			return -5;
		}
		if (0 > keys[i]) {
			/** @type {number} */
			val = 1;
		} else {
			if (3 == hash[keys[i]]) {
				return 3;
			}
			if (keys[i] == parent) {
				return -5;
			}
			if (0 != keys[i]) {
				/** @type {number} */
				val = 1;
			}
		}
	}
	return val;
}
/**
 * @param {number} i
 * @param {number} s
 * @param {number} ch
 * @return {undefined}
 */
function match(i, s, ch) {
	var h;
	var t = new Vector;
	var f;
	var g;
	if (0 == lines[i]) {
		if (42 == url && hasToggledVideo || 42 == l && hasToggledAudio) {
			/** @type {number} */
			f = 20;
			/** @type {number} */
			h = s;
			for (; h < ch; h++) {
				/** @type {number} */
				t.x = value - row[h].x;
				/** @type {number} */
				t.y = y - row[h].y;
				g = expect(t);
				if (20 > g && g < f) {
					f = g;
					/** @type {number} */
					lines[i] = h - s + 1;
				}
			}
		}
	} else {
		if (42 == url && target || 42 == l && cmp) {
			vertices[s + lines[i] - 1].x += 0.2 * (value - vertices[s + lines[i] - 1].x);
			vertices[s + lines[i] - 1].y += 0.2 * (y - vertices[s + lines[i] - 1].y);
		} else {
			/** @type {number} */
			lines[i] = 0;
		}
	}
}
/**
 * @param {number} line
 * @param {number} pos
 * @param {!Object} x
 * @return {undefined}
 */
function func(line, pos, x) {
	var i;
	/** @type {number} */
	i = 0;
	for (; i < _len; i++) {
		if (0 == plugins[i]) {
			cb(objects[i], line + 0.5, pos + 0.5);
			cb(nodes[i], 0, 0);
			/** @type {number} */
			plugins[i] = 1;
			/** @type {number} */
			cache[i] = 0;
			/** @type {number} */
			states[i] = 0;
			/** @type {!Object} */
			data[i] = x;
			break;
		}
	}
}
/**
 * @param {number} i
 * @param {number} type
 * @param {number} id
 * @return {?}
 */
function visit(i, type, id) {
	if (data[i] != _) {
		if (data[i] == name) {
			if (type == options) {
				return call(id), 1;
			}
			if (6 == type) {
				/** @type {number} */
				args[id] = number;
				/** @type {number} */
				arr[id] = 0;
			} else {
				if (type == current) {
					/** @type {number} */
					index = current;
				} else {
					if (11 == type) {
						if (20 <= ++cache[i]) {
							/** @type {number} */
							index = current;
						}
					} else {
						if (type == object) {
							return 1;
						}
						if (type == elem) {
							call(id);
						} else {
							if (type == end) {
								return 1;
							}
							if (type == val) {
								if (10 > apply(100)) {
									/** @type {number} */
									args[id] = _;
									/** @type {number} */
									arr[id] = 0;
								}
							} else {
								if (type == title) {
									return 1;
								}
								if (type == size) {
									if (20 <= ++cache[i]) {
										/** @type {number} */
										index = 37;
									}
									call(id);
								} else {
									if (type == action) {
										/** @type {number} */
										args[id] = message;
										/** @type {number} */
										arr[id] = 0;
									}
								}
							}
						}
					}
				}
			}
		} else {
			if (data[i] == current) {
				if (type == name) {
					/** @type {number} */
					args[id] = current;
					/** @type {number} */
					arr[id] = 0;
				} else {
					if (type == options) {
						if (20 <= ++cache[i]) {
							/** @type {number} */
							index = name;
						}
					} else {
						if (type == current) {
							/** @type {number} */
							cache[i] = 0;
						} else {
							if (11 == type) {
								/** @type {number} */
								cache[i] = 0;
							} else {
								if (type == object) {
									/** @type {number} */
									index = name;
								} else {
									if (type == elem) {
										if (20 <= ++cache[i]) {
											/** @type {number} */
											index = name;
										}
									} else {
										if (type == end) {
											return 1;
										}
										if (type == title) {
											if (20 <= ++cache[i]) {
												/** @type {number} */
												index = name;
											}
										} else {
											if (type == event && 20 <= ++cache[i]) {
												/** @type {number} */
												index = name;
											}
										}
									}
								}
							}
						}
					}
				}
			} else {
				if (37 == data[i]) {
					if (type == name) {
						/** @type {number} */
						cache[i] = 0;
					} else {
						if (type == options) {
							return 20 <= ++cache[i] && (index = size), call(id), 1;
						}
						if (type == number) {
							/** @type {number} */
							args[id] = _;
							/** @type {number} */
							arr[id] = 0;
						} else {
							if (6 == type) {
								/** @type {number} */
								args[id] = _;
								/** @type {number} */
								arr[id] = 0;
							} else {
								if (type == current) {
									/** @type {number} */
									index = current;
								} else {
									if (11 == type) {
										if (20 <= ++cache[i]) {
											/** @type {number} */
											index = current;
										}
									} else {
										if (type == object) {
											/** @type {number} */
											index = size;
										} else {
											if (type == elem) {
												if (20 <= ++cache[i]) {
													/** @type {number} */
													index = size;
												}
												call(id);
											} else {
												if (type == end) {
													return 1;
												}
												if (type == val) {
													/** @type {number} */
													args[id] = _;
													/** @type {number} */
													arr[id] = 0;
												} else {
													if (type == title) {
														return 20 <= ++cache[i] && (index = size), 1;
													}
													if (type == p) {
														/** @type {number} */
														args[id] = _;
														/** @type {number} */
														arr[id] = 0;
													} else {
														if (type == size) {
															if (20 > cache[i]) {
																call(id);
																cache[i]++;
															}
														} else {
															if (type == event) {
																if (20 <= ++cache[i]) {
																	/** @type {number} */
																	index = size;
																}
																call(id);
															} else {
																if (type == action) {
																	/** @type {number} */
																	args[id] = message;
																	/** @type {number} */
																	arr[id] = 0;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				} else {
					if (data[i] == size) {
						if (type == name) {
							/** @type {number} */
							index = 37;
						} else {
							if (type == object || type == end) {
								return 1;
							}
						}
					} else {
						if (data[i] == options) {
							if (type == _) {
								/** @type {number} */
								args[id] = options;
								/** @type {number} */
								arr[id] = 0;
							} else {
								if (type == number) {
									/** @type {number} */
									args[id] = options;
									/** @type {number} */
									arr[id] = 0;
								} else {
									if (6 == type) {
										/** @type {number} */
										args[id] = options;
										/** @type {number} */
										arr[id] = 0;
									} else {
										if (type == message) {
											/** @type {number} */
											args[id] = options;
											/** @type {number} */
											arr[id] = 0;
										} else {
											if (type == current) {
												/** @type {number} */
												args[id] = name;
												/** @type {number} */
												arr[id] = 0;
											} else {
												if (11 == type) {
													/** @type {number} */
													args[id] = name;
													/** @type {number} */
													arr[id] = 0;
												} else {
													if (type == all) {
														if (args[id] == all && 0 < arr[id] && 100 > arr[id]) {
															items[id].y -= 50;
															arr[id] += 100;
														}
													} else {
														if (type == r) {
															/** @type {number} */
															args[id] = options;
															/** @type {number} */
															arr[id] = 0;
														} else {
															if (type == command) {
																/** @type {number} */
																args[id] = options;
																/** @type {number} */
																arr[id] = 0;
															} else {
																if (type == code) {
																	/** @type {number} */
																	args[id] = options;
																	/** @type {number} */
																	arr[id] = 0;
																} else {
																	if (type == group) {
																		/** @type {number} */
																		args[id] = options;
																		/** @type {number} */
																		arr[id] = 0;
																	} else {
																		if (type == date) {
																			/** @type {number} */
																			args[id] = options;
																			/** @type {number} */
																			arr[id] = 0;
																		} else {
																			if (type == p) {
																				/** @type {number} */
																				args[id] = options;
																				/** @type {number} */
																				arr[id] = 0;
																			} else {
																				if (type == node) {
																					/** @type {number} */
																					args[id] = options;
																					/** @type {number} */
																					arr[id] = 0;
																				} else {
																					if (type == action) {
																						/** @type {number} */
																						args[id] = options;
																						/** @type {number} */
																						arr[id] = 0;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						} else {
							if (data[i] == number) {
								if (type == _) {
									if (1 == cache[i]) {
										/** @type {number} */
										index = 6;
									} else {
										/** @type {number} */
										args[id] = number;
										/** @type {number} */
										arr[id] = 0;
									}
								} else {
									if (type == name) {
										/** @type {number} */
										cache[i] = 1;
									} else {
										if (type == p) {
											/** @type {number} */
											args[id] = 6;
											/** @type {number} */
											arr[id] = 0;
										}
									}
								}
							} else {
								if (6 == data[i]) {
									if (type == number) {
										/** @type {number} */
										arr[id] = 1;
									} else {
										if (type == r) {
											/** @type {number} */
											cache[i] = 1;
										}
									}
								} else {
									if (data[i] == message) {
										if (type == name) {
											if (20 > cache[i]) {
												cache[i]++;
											}
										} else {
											if (type == options) {
												if (0 < cache[i]) {
													cache[i]--;
												}
											} else {
												if (type == object) {
													if (0 < cache[i]) {
														cache[i]--;
													}
												} else {
													if (type == elem) {
														if (0 < cache[i]) {
															cache[i]--;
														}
													} else {
														if (type == v) {
															if (20 > cache[i]) {
																cache[i]++;
															}
														} else {
															if (type == end) {
																if (0 < cache[i]) {
																	cache[i]--;
																}
															} else {
																if (type == title) {
																	if (0 < cache[i]) {
																		cache[i]--;
																	}
																} else {
																	if (37 == type) {
																		if (20 > cache[i]) {
																			cache[i]++;
																		}
																	} else {
																		if (type == event && 0 < cache[i]) {
																			cache[i]--;
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									} else {
										if (data[i] == r) {
											if (type == object) {
												return 1;
											}
											if (type == v) {
												call(id);
											} else {
												if (type == end || type == title) {
													return 1;
												}
												if (type == action && 256 > arr[id]) {
													/** @type {number} */
													arr[id] = r;
												}
											}
										} else {
											if (data[i] == v) {
												if (type == current) {
													/** @type {number} */
													index = current;
												} else {
													if (type == r) {
														call(id);
													} else {
														if (type == object) {
															return 1;
														}
														if (type == elem) {
															call(id);
														} else {
															if (type == end || type == title) {
																return 1;
															}
															if (type == event) {
																call(id);
															} else {
																if (type == action && 256 > arr[id]) {
																	/** @type {number} */
																	arr[id] = v;
																}
															}
														}
													}
												}
											} else {
												if (data[i] != id) {
													if (data[i] == string) {
														if (type == end || type == title) {
															return 1;
														}
													} else {
														if (data[i] == delimiter) {
															if (0 == cache[i] && 0 < type) {
																/** @type {number} */
																cache[i] = type;
															} else {
																if (0 != cache[i] && 0 < type) {
																	args[id] = cache[i];
																	/** @type {number} */
																	arr[id] = 0;
																	/** @type {number} */
																	map[id] = 0;
																}
															}
														} else {
															if (data[i] == code) {
																if (type == action && 256 > arr[id]) {
																	/** @type {number} */
																	arr[id] = code;
																}
															} else {
																if (data[i] == parent) {
																	if (0 == c1[type] && type != string || call(id), type == end || type == title) {
																		return 1;
																	}
																} else {
																	if (data[i] == node) {
																		if (!(type != number && type != group)) {
																			call(id);
																		}
																		if (6 == type) {
																			parse(nodes[i], 0.9);
																		}
																	} else {
																		if (data[i] == end) {
																			if (37 == type) {
																				return args[id] = end, arr[id] = 0;
																			}
																			if (type == end) {
																				return 1;
																			}
																			if (type == val) {
																				/** @type {number} */
																				args[id] = end;
																				/** @type {number} */
																				arr[id] = 6E3;
																			} else {
																				if (type == undefined) {
																					return args[id] = end, arr[id] = 6100, 1;
																				}
																			}
																		} else {
																			if (data[i] == tag) {
																				if (type == name) {
																					/** @type {number} */
																					cache[i] = 0;
																				} else {
																					if (type == object) {
																						if (20 <= ++cache[i]) {
																							/** @type {number} */
																							index = object;
																						}
																					} else {
																						if (type == tag) {
																							if (!(1E3 > beginHint[max] - k) && 10 < nodes[i].x * nodes[i].x + nodes[i].y * nodes[i].y) {
																								/** @type {number} */
																								id = parseInt(objects[i].x) + parseInt(apply(5)) - 2;
																								/** @type {number} */
																								var w = parseInt(objects[i].y) + parseInt(apply(5)) - 2;
																								/** @type {number} */
																								var j = w * length + id;
																								if (obj[j] <= temp) {
																									callback(id, w, event);
																								}
																							}
																						} else {
																							if (type == event) {
																								return 1;
																							}
																						}
																					}
																				}
																			} else {
																				if (data[i] == object) {
																					if (type == name) {
																						if (20 <= ++cache[i]) {
																							/** @type {number} */
																							index = val;
																						}
																						/** @type {number} */
																						args[id] = n;
																						/** @type {number} */
																						arr[id] = 0;
																					} else {
																						if (type == object) {
																							/** @type {number} */
																							cache[i] = 0;
																						} else {
																							if (type == v) {
																								if (20 <= ++cache[i]) {
																									/** @type {number} */
																									index = key;
																								}
																								/** @type {number} */
																								args[id] = n;
																								/** @type {number} */
																								arr[id] = 0;
																							} else {
																								if (37 == type) {
																									if (20 <= ++cache[i]) {
																										/** @type {number} */
																										index = tag;
																									}
																									/** @type {number} */
																									args[id] = n;
																									/** @type {number} */
																									arr[id] = 0;
																								}
																							}
																						}
																					}
																					if (type == _) {
																						/** @type {number} */
																						args[id] = options;
																						/** @type {number} */
																						arr[id] = 0;
																					} else {
																						if (type == number) {
																							/** @type {number} */
																							args[id] = options;
																							/** @type {number} */
																							arr[id] = 0;
																						} else {
																							if (6 == type) {
																								/** @type {number} */
																								args[id] = options;
																								/** @type {number} */
																								arr[id] = 0;
																							} else {
																								if (type == message) {
																									/** @type {number} */
																									args[id] = options;
																									/** @type {number} */
																									arr[id] = 0;
																								} else {
																									if (type == current) {
																										/** @type {number} */
																										args[id] = name;
																										/** @type {number} */
																										arr[id] = 0;
																									} else {
																										if (11 == type) {
																											/** @type {number} */
																											args[id] = name;
																											/** @type {number} */
																											arr[id] = 0;
																										} else {
																											if (type == line) {
																												/** @type {number} */
																												args[id] = options;
																												/** @type {number} */
																												arr[id] = 0;
																											} else {
																												if (type == all) {
																													if (args[id] == all && 0 < arr[id] && 100 > arr[id]) {
																														items[id].y -= 50;
																														arr[id] += 100;
																													}
																												} else {
																													if (type == r) {
																														/** @type {number} */
																														args[id] = options;
																														/** @type {number} */
																														arr[id] = 0;
																													} else {
																														if (type == command) {
																															/** @type {number} */
																															args[id] = options;
																															/** @type {number} */
																															arr[id] = 0;
																														} else {
																															if (type != tag) {
																																if (type == code) {
																																	/** @type {number} */
																																	args[id] = options;
																																	/** @type {number} */
																																	arr[id] = 0;
																																} else {
																																	if (type == group) {
																																		/** @type {number} */
																																		args[id] = options;
																																		/** @type {number} */
																																		arr[id] = 0;
																																	} else {
																																		if (type == date) {
																																			/** @type {number} */
																																			args[id] = options;
																																			/** @type {number} */
																																			arr[id] = 0;
																																		} else {
																																			if (type != val) {
																																				if (type == p) {
																																					/** @type {number} */
																																					args[id] = options;
																																					/** @type {number} */
																																					arr[id] = 0;
																																				} else {
																																					if (type != key) {
																																						if (type == node) {
																																							/** @type {number} */
																																							args[id] = options;
																																							/** @type {number} */
																																							arr[id] = 0;
																																						} else {
																																							if (type != undefined && type == action) {
																																								/** @type {number} */
																																								args[id] = options;
																																								/** @type {number} */
																																								arr[id] = 0;
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				} else {
																					if (data[i] == val) {
																						if (type == name) {
																							/** @type {number} */
																							cache[i] = 0;
																						} else {
																							if (type == object) {
																								if (20 <= ++cache[i]) {
																									/** @type {number} */
																									index = object;
																								}
																							} else {
																								if (type == val) {
																									if (!(1E3 > beginHint[max] - k) && 10 < nodes[i].x * nodes[i].x + nodes[i].y * nodes[i].y) {
																										/** @type {number} */
																										id = parseInt(objects[i].x) + parseInt(apply(5)) - 2;
																										/** @type {number} */
																										w = parseInt(objects[i].y) + parseInt(apply(5)) - 2;
																										/** @type {number} */
																										j = w * length + id;
																										if (obj[j] <= temp) {
																											callback(id, w, event);
																										}
																									}
																								} else {
																									if (type == end || type == title || type == event) {
																										return 1;
																									}
																								}
																							}
																						}
																					} else {
																						if (data[i] == key) {
																							if (type == name) {
																								/** @type {number} */
																								cache[i] = 0;
																							} else {
																								if (type == object) {
																									if (20 <= ++cache[i]) {
																										/** @type {number} */
																										index = object;
																									}
																								} else {
																									if (type == end || type == title) {
																										return 1;
																									}
																								}
																							}
																						} else {
																							if (data[i] == elem) {
																								if (type == _) {
																									/** @type {number} */
																									args[id] = options;
																									/** @type {number} */
																									arr[id] = 0;
																								} else {
																									if (type == number) {
																										/** @type {number} */
																										args[id] = options;
																										/** @type {number} */
																										arr[id] = 0;
																									} else {
																										if (6 == type) {
																											/** @type {number} */
																											args[id] = elem;
																											/** @type {number} */
																											arr[id] = 0;
																										} else {
																											if (type == message) {
																												/** @type {number} */
																												args[id] = options;
																												/** @type {number} */
																												arr[id] = 0;
																											} else {
																												if (type == current) {
																													/** @type {number} */
																													args[id] = name;
																													/** @type {number} */
																													arr[id] = 0;
																												} else {
																													if (11 == type) {
																														/** @type {number} */
																														args[id] = name;
																														/** @type {number} */
																														arr[id] = 0;
																													} else {
																														if (type == line) {
																															/** @type {number} */
																															args[id] = options;
																															/** @type {number} */
																															arr[id] = 0;
																														} else {
																															if (type == all) {
																																if (args[id] == all && 0 < arr[id] && 100 > arr[id]) {
																																	items[id].y -= 50;
																																	arr[id] += 100;
																																}
																															} else {
																																if (type == r) {
																																	/** @type {number} */
																																	args[id] = options;
																																	/** @type {number} */
																																	arr[id] = 0;
																																} else {
																																	if (type == command) {
																																		/** @type {number} */
																																		args[id] = options;
																																		/** @type {number} */
																																		arr[id] = 0;
																																	} else {
																																		if (type == code) {
																																			/** @type {number} */
																																			args[id] = options;
																																			/** @type {number} */
																																			arr[id] = 0;
																																		} else {
																																			if (type == group) {
																																				/** @type {number} */
																																				args[id] = options;
																																				/** @type {number} */
																																				arr[id] = 0;
																																			} else {
																																				if (type == date) {
																																					/** @type {number} */
																																					args[id] = options;
																																					/** @type {number} */
																																					arr[id] = 0;
																																				} else {
																																					if (type == p) {
																																						/** @type {number} */
																																						args[id] = options;
																																						/** @type {number} */
																																						arr[id] = 0;
																																					} else {
																																						if (type == node) {
																																							/** @type {number} */
																																							args[id] = options;
																																							/** @type {number} */
																																							arr[id] = 0;
																																						} else {
																																							if (type == action) {
																																								/** @type {number} */
																																								args[id] = options;
																																								/** @type {number} */
																																								arr[id] = 0;
																																							} else {
																																								if (type == h) {
																																									/** @type {number} */
																																									args[id] = name;
																																									/** @type {number} */
																																									arr[id] = 0;
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							} else {
																								if (data[i] == action) {
																									if (type == r) {
																										/** @type {number} */
																										cache[i] = r;
																									} else {
																										if (type == code) {
																											/** @type {number} */
																											cache[i] = code;
																										} else {
																											if (type == v) {
																												/** @type {number} */
																												cache[i] = v;
																											}
																										}
																									}
																								} else {
																									if (data[i] == h) {
																										if (6 == type) {
																											/** @type {number} */
																											index = name;
																										} else {
																											if (type == current) {
																												/** @type {number} */
																												index = current;
																											} else {
																												if (type == command) {
																													/** @type {number} */
																													index = name;
																												} else {
																													if (type == elem) {
																														/** @type {number} */
																														index = name;
																													} else {
																														if (type == val) {
																															/** @type {number} */
																															index = end;
																														} else {
																															if (type == p) {
																																/** @type {number} */
																																index = name;
																															} else {
																																if (type == action) {
																																	/** @type {number} */
																																	index = name;
																																} else {
																																	if (type == end || type == title) {
																																		return 1;
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									} else {
																										if (data[i] == none && (0 == cache[i] ? type == name ? cache[i] = name : type == r ? cache[i] = r : type == object ? cache[i] = object : type == code ? cache[i] = code : type == date ? cache[i] = date : type == v ? 
																																		cache[i] = v : type == parent ? cache[i] = parent : 37 == type ? cache[i] = 37 : type == undefined ? cache[i] = undefined : type == h && (cache[i] = h) : (w = cache[i] & 255, j = cache[i] >> 8, type == w && (cache[i] = 
																																																																																																							 j + 1 << 8 | w, call(id))), type == object || type == end || type == title)) {
																											return 1;
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 2 == hash[type] && 2 == hash[data[i]] && data[i] != type || 2 == hash[type] && 2 != hash[data[i]] || 5 == hash[type] && 5 != hash[data[i]] || type == options ? 1 : 0;
}
/**
 * @param {number} name
 * @param {!Object} x
 * @param {number} i
 * @param {number} value
 * @param {number} data
 * @param {number} r
 * @param {number} c
 * @param {number} a
 * @return {undefined}
 */
function debug(name, x, i, value, data, r, c, a) {
	if (0 == i) {
		/** @type {number} */
		i = 9;
		for (; 21 > i; i++) {
			/** @type {number} */
			var index = obj[x + attrs[i]];
			if (index <= temp) {
				index = callback(parseInt(objects[name].x) + units[i], parseInt(objects[name].y) + pathsMatches[i], value);
				if (0 < index) {
					items[index].x += r + dots[i] * a;
					items[index].y += c + v2[i] * a;
					/** @type {number} */
					arr[index] = data;
				}
			}
		}
		/** @type {number} */
		plugins[name] = 0;
	} else {
		if (1 == i || 2 == i) {
			/** @type {number} */
			i = 1 == i ? 9 : 0;
			for (; 21 > i; i++) {
				/** @type {number} */
				index = obj[x + attrs[i]];
				if (index <= temp) {
					callback(parseInt(objects[name].x) + units[i], parseInt(objects[name].y) + pathsMatches[i], value);
				} else {
					if (0 <= index) {
						/** @type {number} */
						args[index] = value;
						/** @type {number} */
						arr[index] = 0;
						/** @type {number} */
						map[index] = 0;
					}
				}
			}
			/** @type {number} */
			plugins[name] = 0;
		}
	}
}
/**
 * @param {number} data
 * @param {number} left
 * @param {string} type
 * @param {number} x
 * @param {number} y
 * @param {number} w
 * @param {number} h
 * @return {undefined}
 */
function text(data, left, type, x, y, w, h) {
	try {
		/** @type {(Element|null)} */
		canvas = el.getElementById("cv");
		ctx = canvas.getContext("2d");
		ctx.putImageData(data, left, type, x, y, w, h);
	} catch (q) {
	}
}
/**
 * @param {number} arg
 * @return {undefined}
 */
function fill(arg) {
	try {
		cc.log(arg);
	} catch (d) {
	}
}
/**
 * @return {undefined}
 */
function drawPlayButton() {
	var i;
	fill(points);
	/** @type {number} */
	canvas.width = 400;
	/** @type {number} */
	canvas.height = 456;
	/** @type {number} */
	i = 0;
	for (; 513 > i; i++) {
		/** @type {!Array} */
		grid[i] = Array(2);
	}
	/** @type {number} */
	i = 0;
	for (; 512 > i; i++) {
		/** @type {number} */
		var a = 360 * i / 512 * ratio / 180;
		/** @type {number} */
		grid[i][0] = Math.cos(a);
		/** @type {number} */
		grid[i][1] = Math.sin(a);
	}
	grid[i][0] = grid[0][0];
	grid[i][1] = grid[0][1];
	/** @type {number} */
	i = 0;
	for (; 256 > i; i++) {
		/** @type {boolean} */
		box[i] = false;
		/** @type {boolean} */
		patches[i] = false;
		/** @type {boolean} */
		pairs[i] = false;
		/** @type {number} */
		files[i] = 0;
		/** @type {number} */
		body[i] = 0;
	}
	/** @type {number} */
	i = 0;
	for (; 10 > i; i++) {
		/** @type {number} */
		files[48 + i] = 48 + i;
	}
	/** @type {number} */
	i = 0;
	for (; 9 > i; i++) {
		/** @type {number} */
		body[49 + i] = 33 + i;
	}
	/** @type {number} */
	i = 0;
	for (; 4 > i; i++) {
		/** @type {number} */
		files[37 + i] = 37 + i;
	}
	/** @type {number} */
	i = 0;
	for (; 4 > i; i++) {
		/** @type {number} */
		body[37 + i] = 37 + i;
	}
	/** @type {number} */
	files[13] = body[13] = 13;
	/** @type {number} */
	files[16] = body[16] = 16;
	/** @type {number} */
	files[17] = body[17] = 17;
	/** @type {number} */
	files[18] = body[18] = 18;
	/** @type {number} */
	files[32] = body[32] = 32;
	/** @type {number} */
	files[186] = 58;
	/** @type {number} */
	body[186] = 42;
	/** @type {number} */
	files[187] = 59;
	/** @type {number} */
	body[187] = 43;
	/** @type {number} */
	files[188] = 44;
	/** @type {number} */
	body[188] = 60;
	/** @type {number} */
	files[189] = 45;
	/** @type {number} */
	body[189] = 61;
	/** @type {number} */
	files[190] = 46;
	/** @type {number} */
	body[190] = 62;
	/** @type {number} */
	files[191] = 47;
	/** @type {number} */
	body[191] = 63;
	/** @type {number} */
	files[192] = 64;
	/** @type {number} */
	body[192] = 96;
	/** @type {number} */
	files[219] = 91;
	/** @type {number} */
	body[219] = 123;
	/** @type {number} */
	files[220] = 92;
	/** @type {number} */
	body[220] = 124;
	/** @type {number} */
	files[221] = 93;
	/** @type {number} */
	body[221] = 125;
	/** @type {number} */
	files[222] = 94;
	/** @type {number} */
	body[222] = 126;
	/** @type {number} */
	files[226] = 92;
	/** @type {number} */
	body[226] = 95;
	/** @type {number} */
	files[58] = 58;
	/** @type {number} */
	body[58] = 42;
	/** @type {number} */
	files[59] = 59;
	/** @type {number} */
	body[59] = 43;
	/** @type {number} */
	files[173] = 45;
	/** @type {number} */
	body[173] = 61;
	/** @type {number} */
	files[64] = 64;
	/** @type {number} */
	body[64] = 96;
	/** @type {number} */
	files[160] = 94;
	/** @type {number} */
	body[160] = 126;
	var p;
	/** @type {number} */
	i = 0;
	for (; 1024 > i; i++) {
		/** @type {number} */
		positions[i] = i / 1024;
	}
	/** @type {number} */
	i = 0;
	for (; 1024 > i; i++) {
		a = parseInt(1024 * Math.random());
		/** @type {number} */
		p = positions[i];
		/** @type {number} */
		positions[i] = positions[a];
		/** @type {number} */
		positions[a] = p;
	}
	/** @type {number} */
	aL = parseInt(1024 * Math.random()) & 1023;
	/** @type {number} */
	bL = parseInt(512 * Math.random()) | 1;
	/** @type {number} */
	i = 0;
	for (; i < length * height; i++) {
		/** @type {number} */
		pixels[i] = 0;
	}
	/** @type {number} */
	i = 0;
	for (; i < length * height * 4; i++) {
		/** @type {number} */
		tex[i] = 255;
	}
}
/**
 * @return {undefined}
 */
function resolve() {
	if (callGlobalHandler) {
		callGlobalHandler(resolve);
		Ef++;
		/** @type {number} */
		mouseX = Date.now();
		var x = parseInt(60 * (mouseX - lastMouseX) / 1E3 + 0.5);
		if (0 > x || 60 <= x) {
			/** @type {number} */
			Ef = 0;
			path = idOrPath;
			/** @type {number} */
			idOrPath = 0;
			level = parseInt((2 * level + _Position_OuterEnd) / 3);
			/** @type {number} */
			_Position_OuterEnd = 0;
			/** @type {number} */
			lastMouseX = mouseX;
			/** @type {number} */
			x = 0;
		} else {
			if (x == minx) {
				return;
			}
		}
		idOrPath++;
		minx = x;
	}
	/** @type {boolean} */
	hasToggledVideo = false == target && true == source;
	/** @type {boolean} */
	rx = true == target && false == source;
	/** @type {boolean} */
	hasToggledAudio = false == cmp && true == cursorTrack;
	/** @type {boolean} */
	ry = true == cmp && false == cursorTrack;
	target = source;
	cmp = cursorTrack;
	/** @type {boolean} */
	historyInstance = !(rx | target | ry | cmp);
	/** @type {number} */
	dx = rx ? 1 : ry ? -1 : 0;
	lastLat = lat;
	lastLon = lon;
	lat = version;
	lon = py;
	if (hasToggledVideo) {
		lastLat = lat;
		lastLon = lon;
	}
	/** @type {number} */
	x = 0;
	for (; 256 > x; x++) {
		box[x] = patches[x];
		/** @type {boolean} */
		patches[x] = false;
	}
	/** @type {number} */
	aL = aL + parseInt(1024 * Math.random()) & 1023;
	/** @type {number} */
	bL = parseInt(512 * Math.random()) | 1;
	init();
	var d;
	/** @type {number} */
	var eleSize = 11 == i ? length * height : 0;
	if (0 == tileSize) {
		/** @type {number} */
		d = x = 0;
	} else {
		var c = parseInt(time) + 8;
		var pos = parseInt(delta) + 8;
		var lonExtra;
		var latExtra;
		var p;
		/** @type {number} */
		latExtra = 0;
		for (; 300 > latExtra; latExtra++) {
			/** @type {number} */
			d = 4 * ((latExtra + 8) * length + 8);
			x = (pos + (latExtra >> tileSize)) * length + (c + 0);
			/** @type {number} */
			lonExtra = 0;
			for (; 400 > lonExtra; lonExtra++) {
				p = x + (lonExtra >> tileSize);
				/** @type {number} */
				tex[d++] = pixels[p] >> 16 & 255;
				/** @type {number} */
				tex[d++] = pixels[p] >> 8 & 255;
				/** @type {number} */
				tex[d++] = pixels[p] & 255;
				d++;
			}
		}
		/** @type {number} */
		x = 308 * length;
		/** @type {number} */
		d = 4 * x;
	}
	for (; x < eleSize; x++) {
		/** @type {number} */
		tex[d++] = pixels[x] >> 16 & 255;
		/** @type {number} */
		tex[d++] = pixels[x] >> 8 & 255;
		/** @type {number} */
		tex[d++] = pixels[x] & 255;
		d++;
	}
	text(opts, -8, -8, 8, 8, length - 16, height - 8);
	if (callGlobalHandler) {
		/** @type {number} */
		_Position_OuterEnd = _Position_OuterEnd + (Date.now() - mouseX);
	} else {
		emit(resolve, sendMessage());
	}
}
/**
 * @return {?}
 */
function closeDropdownsIn() {
	console.log("checking");
	if (dump1.length != dump2.length) {
		return true;
	}
	/** @type {number} */
	Pb = 0;
	for (; i < dump1.length; i++) {
		if (dump1[i] != dump2[i]) {
			return true;
		}
	}
	return false;
}
/**
 * @return {?}
 */
function sendMessage() {
	/** @type {number} */
	mouseX = Date.now();
	var offset = clamp(startX - mouseX, 5, offsetX);
	idOrPath++;
	Rf++;
	_Position_OuterEnd = _Position_OuterEnd + offset;
	startX = startX + offsetX;
	if (mouseX + offset >= oldmouseX || mouseX < lastMouseX) {
		/** @type {number} */
		level = level + _Position_OuterEnd >> 1;
		/** @type {number} */
		_Position_OuterEnd = 0;
		path = idOrPath;
		/** @type {number} */
		idOrPath = 0;
		/** @type {number} */
		startX = mouseX + offsetX;
		/** @type {number} */
		oldmouseX = mouseX + 1E3;
	}
	/** @type {number} */
	lastMouseX = mouseX;
	return offset;
}
/**
 * @return {undefined}
 */
function Matrix() {
	/** @type {number} */
	this.d = 0;
	/** @type {string} */
	this.file = "";
	/** @type {number} */
	this.u = this.f = this.n = this.g = this.k = this.b = this.shift = this.i = this.c = 0;
}
/**
 * @param {!Object} a
 * @param {number} start
 * @param {number} data
 * @return {undefined}
 */
function test(a, start, data) {
	/** @type {number} */
	a.c = start;
	/** @type {number} */
	a.i = data;
	/** @type {number} */
	start = a.shift = 0;
	for (; 16 > start; start++) {
		if (1 << start == a.c) {
			/** @type {number} */
			a.shift = start;
		}
	}
	/** @type {!Int32Array} */
	a.b = new Int32Array(a.c * a.i);
}
/**
 * @param {!Object} o
 * @return {undefined}
 */
function draw(o) {
	if (0 == o.k && o.d.complete) {
		Cb--;
		var w = o.d.width;
		var h = o.d.height;
		if (0 == w || 0 == h) {
			throw delete o.d, o.file = "", $gBCRBottom;
		}
		/** @type {!Element} */
		var c = el.createElement(wrapper);
		c.width = w;
		c.height = h;
		c = c.getContext(origin);
		c.drawImage(o.d, 0, 0);
		c = c.getImageData(0, 0, w, h).data;
		test(o, w, h);
		/** @type {number} */
		w = 0;
		h = c.length;
		for (; w < h; w = w + 4) {
			/** @type {number} */
			o.b[w >> 2] = 0 == c[w + 3] ? -1 : c[w + 0] << 16 | c[w + 1] << 8 | c[w + 2];
		}
		delete o.d;
		/** @type {number} */
		o.k = 1;
	}
}
/**
 * @param {!Object} value
 * @param {string} obj
 * @return {undefined}
 */
function generate(value, obj) {
	render(value, obj, "sans-serif", 0, 14);
}
/**
 * @param {!Object} self
 * @param {number} id
 * @param {string} key
 * @param {number} i
 * @param {number} h
 * @return {undefined}
 */
function render(self, id, key, i, h) {
	if (0 == self.k) {
		/** @type {number} */
		self.k = 1;
		test(self, length, 128);
		/** @type {!Element} */
		self.n = el.createElement(wrapper);
		self.n.width = self.c;
		self.n.height = self.i;
		self.f = self.n.getContext(origin);
	}
	var url = id + key + i + h;
	if (self.u != url) {
		self.u = url;
		/** @type {string} */
		self.f.fillStyle = "#000000";
		self.f.fillRect(0, 0, self.c, self.i);
		/** @type {string} */
		url = "";
		if (0 != (i & 2)) {
			/** @type {string} */
			url = url + "italic ";
		}
		if (0 != (i & 1)) {
			/** @type {string} */
			url = url + "bold ";
		}
		/** @type {string} */
		url = url + (h + "px ") + key;
		/** @type {string} */
		self.f.font = url;
		/** @type {string} */
		self.f.fillStyle = "#ffffff";
		self.f.fillText(id, 0, h);
		key = self.f.getImageData(0, 0, self.c, self.i).data;
		/** @type {number} */
		id = 0;
		i = key.length;
		for (; id < i; id = id + 4) {
			/** @type {number} */
			self.b[id >> 2] = 1 <= key[id + 0] ? 16777215 : -1;
		}
		/** @type {number} */
		id = key = self.g = 0;
		for (; key < self.i; key++) {
			/** @type {number} */
			i = 0;
			for (; i < self.c; i++, id++) {
				if (16777215 == self.b[id] && self.g <= i) {
					/** @type {number} */
					self.g = i + 1;
				}
			}
		}
	}
}
/**
 * @return {undefined}
 */
function clone() {
	this.o = new Matrix;
	/** @type {number} */
	this.j = this.m = this.p = this.h = 0;
}
/**
 * @param {number} n
 * @param {number} data
 * @param {string} type
 * @param {number} i
 * @return {undefined}
 */
function show(n, data, type, i) {
	var a = self;
	/** @type {number} */
	n = n - (type.length * (a.h + a.m) >> 1);
	/** @type {number} */
	data = data - (a.p >> 1);
	a.a(n, data, type, i, 0);
}
/**
 * @param {number} s
 * @param {number} data
 * @param {string} key
 * @param {number} mode
 * @param {number} value
 * @param {number} modules
 * @return {undefined}
 */
function drawText(s, data, key, mode, value, modules) {
	var that = self;
	/** @type {number} */
	that.m = modules;
	that.a(s, data, key, mode, value);
	/** @type {number} */
	that.m = 0;
}
/**
 * @param {number} val
 * @param {number} a
 * @param {number} b
 * @return {?}
 */
function equal(val, a, b) {
	/** @type {number} */
	var t = div;
	/** @type {number} */
	var x = 0;
	/** @type {number} */
	var y = 0;
	/** @type {number} */
	var title = 0;
	if (1 == t) {
		/** @type {number} */
		t = val >> 16 & 255;
		/** @type {number} */
		x = (((a >> 16 & 255) - t) * b >> 8) + t;
		/** @type {number} */
		t = val >> 8 & 255;
		/** @type {number} */
		y = (((a >> 8 & 255) - t) * b >> 8) + t;
		/** @type {number} */
		t = val & 255;
		/** @type {number} */
		title = (((a & 255) - t) * b >> 8) + t;
	} else {
		if (2 == t) {
			/** @type {number} */
			x = ((a >> 16 & 255) * b >> 8) + (val >> 16 & 255);
			if (255 < x) {
				/** @type {number} */
				x = 255;
			}
			/** @type {number} */
			y = ((a >> 8 & 255) * b >> 8) + (val >> 8 & 255);
			if (255 < y) {
				/** @type {number} */
				y = 255;
			}
			/** @type {number} */
			title = ((a & 255) * b >> 8) + (val & 255);
			if (255 < title) {
				/** @type {number} */
				title = 255;
			}
		} else {
			if (3 == t) {
				/** @type {number} */
				x = (val >> 16 & 255) - ((a >> 16 & 255) * b >> 8);
				if (0 > x) {
					/** @type {number} */
					x = 0;
				}
				/** @type {number} */
				y = (val >> 8 & 255) - ((a >> 8 & 255) * b >> 8);
				if (0 > y) {
					/** @type {number} */
					y = 0;
				}
				/** @type {number} */
				title = (val & 255) - ((a & 255) * b >> 8);
				if (0 > title) {
					/** @type {number} */
					title = 0;
				}
			} else {
				if (4 == t) {
					/** @type {number} */
					x = (a >> 16 & 255) * (val >> 16 & 255) >> 8;
					/** @type {number} */
					y = (a >> 8 & 255) * (val >> 8 & 255) >> 8;
					/** @type {number} */
					title = (a & 255) * (val & 255) >> 8;
				} else {
					if (5 == t) {
						/** @type {number} */
						t = val >> 16 & 255;
						/** @type {number} */
						x = t + ((a >> 16 & 255) * t * b >> 16);
						if (255 < x) {
							/** @type {number} */
							x = 255;
						}
						/** @type {number} */
						t = val >> 8 & 255;
						/** @type {number} */
						y = t + ((a >> 8 & 255) * t * b >> 16);
						if (255 < y) {
							/** @type {number} */
							y = 255;
						}
						/** @type {number} */
						t = val & 255;
						/** @type {number} */
						title = t + ((a & 255) * t * b >> 16);
						if (255 < title) {
							/** @type {number} */
							title = 255;
						}
					} else {
						if (6 == t) {
							/** @type {number} */
							t = val >> 16 & 255;
							/** @type {number} */
							x = t + (b - (2 * t * b >> 8));
							/** @type {number} */
							t = val >> 8 & 255;
							/** @type {number} */
							y = t + (b - (2 * t * b >> 8));
							/** @type {number} */
							t = val & 255;
							/** @type {number} */
							title = t + (b - (2 * t * b >> 8));
						}
					}
				}
			}
		}
	}
	return x << 16 | y << 8 | title;
}
/**
 * @param {number} t
 * @param {number} x
 * @param {number} y
 * @param {number} a
 * @param {number} id
 * @return {undefined}
 */
function add(t, x, y, a, id) {
	/** @type {number} */
	y = y - t;
	/** @type {number} */
	a = a - x;
	var i;
	var h;
	if (abs(y) >= abs(a)) {
		h = parseInt(abs(y));
		if (0 != h) {
			a = parseInt(65536 * a / h);
		}
		/** @type {number} */
		y = 0 <= y ? 65536 : -65536;
	} else {
		h = parseInt(abs(a));
		if (0 != h) {
			y = parseInt(65536 * y / h);
		}
		/** @type {number} */
		a = 0 <= a ? 65536 : -65536;
	}
	t = parseInt(65536 * t) + 32768;
	x = parseInt(65536 * x) + 32768;
	for (; 0 <= h; h--, t = t + y, x = x + a) {
		if (!(0 > t || length <= t >> 16 || 0 > x || height <= x >> 16)) {
			/** @type {number} */
			i = (x >> 16) * length + (t >> 16);
			pixels[i] = 0 == div ? id : equal(pixels[i], id, id >> 24 & 255);
		}
	}
}
/**
 * @param {number} n
 * @param {number} value
 * @param {number} i
 * @param {number} s
 * @param {number} index
 * @return {undefined}
 */
function filter(n, value, i, s, index) {
	i--;
	s--;
	add(n, value, n + i, value, index);
	add(n, value + s, n + i, value + s, index);
	add(n, value, n, value + s, index);
	add(n + i, value, n + i, value + s, index);
}
/**
 * @param {number} i
 * @param {number} index
 * @param {number} offset
 * @param {number} width
 * @param {number} data
 * @return {undefined}
 */
function drawLine(i, index, offset, width, data) {
	var len;
	/** @type {number} */
	offset = i + offset > length ? length : ~~(i + offset);
	/** @type {number} */
	width = index + width > height ? height : ~~(index + width);
	/** @type {number} */
	i = 0 > i ? 0 : ~~i;
	/** @type {number} */
	index = (0 > index ? 0 : ~~index) * length + i;
	/** @type {number} */
	len = length - (offset - i);
	/** @type {number} */
	offset = index + offset - i;
	/** @type {number} */
	width = width * length;
	if (0 == div) {
		for (; index < width; index = index + len, offset = offset + length) {
			for (; index < offset; index++) {
				/** @type {number} */
				pixels[index] = data;
			}
		}
	} else {
		for (; index < width; index = index + len, offset = offset + length) {
			for (; index < offset; index++) {
				pixels[index] = equal(pixels[index], data, data >> 24 & 255);
			}
		}
	}
}
/**
 * @param {!Object} value
 * @param {number} i
 * @param {number} y
 * @param {number} size
 * @param {number} width
 * @param {number} z
 * @param {number} n
 * @param {number} t
 * @return {undefined}
 */
function append(value, i, y, size, width, z, n, t) {
	var dd;
	var offset;
	var j;
	var index;
	var skeleton;
	var a;
	if (0 != size && 0 != width) {
		z = parseInt((z << 8) / size);
		n = parseInt((n << 8) / width);
		/** @type {number} */
		offset = dd = 0;
		if (0 > i) {
			/** @type {number} */
			dd = dd + z * -i;
		}
		if (0 > y) {
			/** @type {number} */
			offset = offset + n * -y;
		}
		size = i + size > length ? length : parseInt(i + size);
		width = y + width > height ? height : parseInt(y + width);
		i = 0 > i ? 0 : parseInt(i);
		y = 0 > y ? 0 : parseInt(y);
		/** @type {number} */
		var c = t >> 24 & 255;
		/** @type {number} */
		var angleToDraw = t >> 16 & 255;
		/** @type {number} */
		var mesh_size_x = t >> 8 & 255;
		/** @type {number} */
		var num = t & 255;
		var x;
		var b;
		if (0 == Yf) {
			for (; y < width; y++, offset = offset + n) {
				index = y * length + i;
				/** @type {number} */
				skeleton = ((offset >> 8) * value.c << 8) + dd;
				/** @type {number} */
				j = i;
				for (; j < size; j++, index++, skeleton = skeleton + z) {
					a = value.b[skeleton >> 8];
					if (-1 != a) {
						/** @type {number} */
						t = angleToDraw * (a >> 16 & 255) >> 8;
						/** @type {number} */
						x = mesh_size_x * (a >> 8 & 255) >> 8;
						/** @type {number} */
						b = num * (a & 255) >> 8;
						if (0 == div) {
							/** @type {number} */
							pixels[index] = t << 16 | x << 8 | b;
						} else {
							if (1 == div) {
								/** @type {number} */
								a = pixels[index] >> 16 & 255;
								/** @type {number} */
								t = ((t - a) * c >> 8) + a;
								/** @type {number} */
								a = pixels[index] >> 8 & 255;
								/** @type {number} */
								x = ((x - a) * c >> 8) + a;
								/** @type {number} */
								a = pixels[index] & 255;
								/** @type {number} */
								b = ((b - a) * c >> 8) + a;
								/** @type {number} */
								pixels[index] = t << 16 | x << 8 | b;
							} else {
								if (2 == div) {
									/** @type {number} */
									t = (t * c >> 8) + (pixels[index] >> 16 & 255);
									if (255 < t) {
										/** @type {number} */
										t = 255;
									}
									/** @type {number} */
									x = (x * c >> 8) + (pixels[index] >> 8 & 255);
									if (255 < x) {
										/** @type {number} */
										x = 255;
									}
									/** @type {number} */
									b = (b * c >> 8) + (pixels[index] & 255);
									if (255 < b) {
										/** @type {number} */
										b = 255;
									}
									/** @type {number} */
									pixels[index] = t << 16 | x << 8 | b;
								} else {
									if (5 == div) {
										/** @type {number} */
										a = pixels[index] >> 16 & 255;
										/** @type {number} */
										t = a + (t * a * c >> 16);
										if (255 < t) {
											/** @type {number} */
											t = 255;
										}
										/** @type {number} */
										a = pixels[index] >> 8 & 255;
										/** @type {number} */
										x = a + (x * a * c >> 16);
										if (255 < x) {
											/** @type {number} */
											x = 255;
										}
										/** @type {number} */
										a = pixels[index] & 255;
										/** @type {number} */
										b = a + (b * a * c >> 16);
										if (255 < b) {
											/** @type {number} */
											b = 255;
										}
										/** @type {number} */
										pixels[index] = t << 16 | x << 8 | b;
									}
								}
							}
						}
					}
				}
			}
		} else {
			if (1 == Yf) {
				for (; y < width; y++, offset = offset + n) {
					index = y * length + i;
					/** @type {number} */
					skeleton = ((offset >> 8) * value.c << 8) + dd;
					/** @type {number} */
					j = i;
					for (; j < size; j++, index++, skeleton = skeleton + z) {
						/** @type {number} */
						a = c * (value.b[skeleton >> 8] & 255) >> 8;
						if (0 != a) {
							pixels[index] = equal(pixels[index], t, a);
						}
					}
				}
			} else {
				if (2 == Yf) {
					for (; y < width; y++, offset = offset + n) {
						index = y * length + i;
						/** @type {number} */
						skeleton = ((offset >> 8) * value.c << 8) + dd;
						/** @type {number} */
						j = i;
						for (; j < size; j++, index++, skeleton = skeleton + z) {
							a = value.b[skeleton >> 8];
							if (0 != a) {
								/** @type {number} */
								t = a >> 16 & 255;
								/** @type {number} */
								x = a >> 8 & 255;
								/** @type {number} */
								b = a & 255;
								/** @type {number} */
								pixels[index] = t == x && x == b ? angleToDraw * t >> 8 << 16 | mesh_size_x * x >> 8 << 8 | num * b >> 8 : t << 16 | x << 8 | b;
							}
						}
					}
				}
			}
		}
	}
}
/**
 * @param {number} id
 * @return {undefined}
 */
function addMemberToDiscussion(id) {
	var i = str.g;
	append(str, 208 - (i >> 1), id - 8, i, 16, str.g, 16, 4278190080);
}
/**
 * @param {number} n
 * @param {number} p
 * @param {number} i
 * @param {number} nr
 * @return {?}
 */
function repeat(n, p, i, nr) {
	return lat < n || n + i <= lat || lon < p || p + nr <= lon ? false : true;
}
/**
 * @param {!Event} event
 * @return {undefined}
 */
function _getColorCanvas(event) {
	var layerRect = canvas.getBoundingClientRect();
	version = parseInt(event.clientX - layerRect.left);
	py = parseInt(event.clientY - layerRect.top);
}
/**
 * @param {!Object} t
 * @return {undefined}
 */
function drag(t) {
	/** @type {number} */
	var offsetX = 0;
	/** @type {number} */
	var offsetY = 0;
	var obj = canvas;
	for (; null !== obj; obj = obj.offsetParent) {
		offsetX = offsetX + obj.offsetLeft;
		offsetY = offsetY + obj.offsetTop;
	}
	t = t.touches;
	version = parseInt(t[0].pageX - offsetX);
	py = parseInt(t[0].pageY - offsetY);
}
/**
 * @param {string} value
 * @param {string} cb
 * @return {?}
 */
function extend(value, cb) {
	/** @type {null} */
	var ret = null;
	try {
		/** @type {(null|string)} */
		ret = prompt(value, cb);
	} catch (c) {
	}
	return ret;
}
/**
 * @param {!Object} filename
 * @param {string} chunk
 * @return {?}
 */
function load(filename, chunk) {
	/** @type {number} */
	var ML_SCRIPT_DATA = Hb = 0;
	for (; 100 > ML_SCRIPT_DATA; ML_SCRIPT_DATA++) {
		/** @type {string} */
		markup_classes[ML_SCRIPT_DATA] = "";
	}
	try {
		/** @type {!XMLHttpRequest} */
		var req = new XMLHttpRequest;
		/**
		 * @return {undefined}
		 */
		req.onreadystatechange = function() {
			if (4 == req.readyState) {
				if (200 == req.status) {
					var i;
					var tagName;
					/** @type {number} */
					var ML_STYLE_DATA = 0;
					/** @type {number} */
					var goal = req.responseText.length;
					/** @type {number} */
					i = 0;
					for (; i < goal; i++) {
						if (tagName = req.responseText[i], tagName == footer) {
							/** @type {number} */
							i = i + 1;
							for (; i < goal; i++) {
								tagName = req.responseText[i];
								if (tagName == span) {
									break;
								}
								markup_classes[ML_STYLE_DATA] += tagName;
							}
							ML_STYLE_DATA++;
						} else {
							for (; i < goal && req.responseText[i] != span; i++) {
							}
						}
					}
					/** @type {number} */
					Hb = 1;
				} else {
					/** @type {number} */
					Hb = -1;
				}
			}
		};
		req.open(copy, filename, false);
		req.setRequestHeader(header, token);
		req.send(chunk);
		return req.responseText;
	} catch (e) {
		/** @type {number} */
		Hb = -2;
	}
	return "";
}
/**
 * @return {undefined}
 */
function Vector() {
	/** @type {number} */
	this.y = this.x = 0;
}
/**
 * @param {!Object} d
 * @param {number} a
 * @param {number} v
 * @return {undefined}
 */
function cb(d, a, v) {
	/** @type {number} */
	d.x = a;
	/** @type {number} */
	d.y = v;
}
/**
 * @param {!Object} d
 * @param {!Object} a
 * @param {!Object} b
 * @return {undefined}
 */
function equals(d, a, b) {
	/** @type {number} */
	d.x = a.x - b.x;
	/** @type {number} */
	d.y = a.y - b.y;
}
/**
 * @param {!Object} num
 * @param {number} value
 * @return {undefined}
 */
function parse(num, value) {
	num.x *= value;
	num.y *= value;
}
/**
 * @param {!Object} item
 * @param {!Object} data
 * @param {number} i
 * @return {undefined}
 */
function push(item, data, i) {
	/** @type {number} */
	item.x = data.x * i;
	/** @type {number} */
	item.y = data.y * i;
}
/**
 * @param {!Object} a
 * @return {?}
 */
function expect(a) {
	return fastDist(a.x, a.y);
}
/**
 * @param {number} vector
 * @return {?}
 */
function dist(vector) {
	return Math.sqrt(vector.x * vector.x + vector.y * vector.y);
}
/**
 * @param {!Object} a
 * @return {?}
 */
function get(a) {
	var distance = fastDist(a.x, a.y);
	if (0 == distance) {
		return 0;
	}
	a.x /= distance;
	a.y /= distance;
	return distance;
}
/**
 * @param {number} point
 * @return {undefined}
 */
function collide(point) {
	var distance = dist(point);
	if (0 != distance) {
		point.x /= distance;
		point.y /= distance;
	}
}
/**
 * @param {!Object} b
 * @return {?}
 */
function angle(b) {
	/** @type {number} */
	var offset = Math.acos(b.x / Math.sqrt(b.x * b.x + b.y * b.y));
	if (0 < b.y) {
		/** @type {number} */
		offset = firstX - offset;
	}
	return offset;
}
/**
 * @param {number} a
 * @param {number} b
 * @return {?}
 */
function fastDist(a, b) {
	if (0 > a) {
		/** @type {number} */
		a = -a;
	}
	if (0 > b) {
		/** @type {number} */
		b = -b;
	}
	return a >= b ? 0.9604 * a + 0.3978 * b : 0.9604 * b + 0.3978 * a;
}
/**
 * @param {number} x1
 * @return {?}
 */
function apply(x1) {
	aL = aL + bL;
	/** @type {number} */
	aL = aL & 1023;
	return positions[aL] * x1;
}
/**
 * @param {number} max
 * @param {number} min
 * @return {?}
 */
function clamp(max, min) {
	aL = aL + bL;
	/** @type {number} */
	aL = aL & 1023;
	return positions[aL] * (min - max) + max;
}
/**
 * @param {number} it
 * @return {?}
 */
function Number(it) {
	aL = aL + bL;
	/** @type {number} */
	aL = aL & 1023;
	return ~~(positions[aL] * it);
}
/**
 * @param {number} val
 * @return {?}
 */
function abs(val) {
	return 0 > val ? -val : val;
}
/**
 * @param {number} n
 * @param {number} r
 * @return {?}
 */
function max(n, r) {
	return n > r ? n : r;
}
/**
 * @param {number} b
 * @param {number} c
 * @return {?}
 */
function min(b, c) {
	return b < c ? b : c;
}
/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {?}
 */
function clamp(a, b, c) {
	return a < b ? b : a > c ? c : a;
}
/**
 * @param {number} b
 * @param {number} a
 * @return {?}
 */
function fn(b, a) {
	return 0 > b ? a : b > a ? 0 : b;
}
/**
 * @param {number} val
 * @return {?}
 */
function parseInt(val) {
	return Math.floor(val);
}
/** @type {number} */
var aa = 0;
/** @type {!Window} */
var msg = window;
/** @type {number} */
var length = 416;
/** @type {number} */
var height = 464;
/** @type {number} */
var url = 0;
/** @type {number} */
var l = 40;
/** @type {boolean} */
var extreme = false;
/** @type {number} */
var w = 2;
/** @type {number} */
var max = 0;
/** @type {!Array} */
var beginHint = [2E4, 3E4, 4E4];
/** @type {number} */
var ja = 0;
/** @type {number} */
var i1 = 2;
/** @type {number} */
var tileSize = 0;
/** @type {number} */
var time = 0;
/** @type {number} */
var delta = 0;
/** @type {number} */
var COLON = 0;
/** @type {number} */
var y1 = 8;
/** @type {number} */
var c = 8;
/** @type {number} */
var y2 = 8;
/** @type {number} */
var b = 8;
/** @type {!Array} */
var results = [];
/** @type {!Array} */
var state = [];
/** @type {number} */
var evalID = -1;
/** @type {number} */
var err = 0;
/** @type {number} */
var gasSum = 0;
/** @type {number} */
var type = 0;
/** @type {number} */
var option = 0;
/** @type {number} */
var bx1 = 0;
/** @type {number} */
var Ca = 0;
/** @type {number} */
var amount = 0;
/** @type {number} */
var x1 = 0;
/** @type {number} */
var next = 0;
/** @type {number} */
var endAttachX = 0;
var str = new Matrix;
/** @type {string} */
var file = "";
/** @type {string} */
var request = "";
/** @type {number} */
var collector = 0;
/** @type {number} */
var x = 0;
/** @type {number} */
var signedTransactionsCounter = 0;
/** @type {!Array} */
var historical_metrics = ["sans-serif", "serif", "monospace", "setFont ->"];
/** @type {!Array} */
var methods = ["PLAIN", "BOLD", "ITALIC", "BOLD&ITALIC"];
/** @type {!Array} */
var signedTransactions = [12, 14, 16, 18, 20, 24, 30, 36, 48, 60, 72];
/** @type {!Array} */
var buffer = Array(309 * length);
/** @type {!Array} */
var sprites = Array(309 * length);
/** @type {!Array} */
var elements = Array(309 * length);
var input = new Matrix;
var arg = new Matrix;
var a;
var d;
/** @type {!Array} */
var parts = [];
/** @type {!Array} */
var ret = [];
/** @type {string} */
var num = "";
/** @type {boolean} */
var isFriend = false;
/** @type {string} */
var deps = "";
var s;
var sum;
var className;
/** @type {number} */
var baseFooterClass = 0;
/** @type {number} */
var costSum = 0;
/** @type {number} */
var lb = 0;
/** @type {number} */
var z = 0;
/** @type {number} */
var zoom = 0;
/** @type {function(number): ?} */
window.GameSave = editorAt;
/** @type {string} */
var part = "";
/** @type {function(string): ?} */
window.GameLoad = createElement;
/** @type {number} */
var wb = 0;
/** @type {function(): undefined} */
msg.fff = init;
var step;
var cols;
var width;
/** @type {number} */
var len = 8216;
/** @type {!Array} */
var values = Array(len);
/** @type {!Array} */
var res = Array(len);
/** @type {!Float32Array} */
var buf = new Float32Array(len);
/** @type {!Float32Array} */
var view = new Float32Array(len);
/** @type {number} */
width = 0;
for (; width < len; width++) {
	values[width] = new Vector;
}
/** @type {number} */
width = 0;
for (; width < len; width++) {
	res[width] = new Vector;
}
var t;
/** @type {!Int32Array} */
var nums = new Int32Array(len);
/** @type {!Int32Array} */
var dst = new Int32Array(len);
/** @type {!Int32Array} */
var out = new Int32Array(len);
var value;
var y;
var total;
var g;
var expected = new Vector;
/** @type {number} */
var _ = 2;
/** @type {number} */
var name = 3;
/** @type {number} */
var options = 4;
/** @type {number} */
var number = 5;
/** @type {number} */
var message = 7;
/** @type {number} */
var id = 8;
/** @type {number} */
var current = 10;
/** @type {number} */
var n = 12;
/** @type {number} */
var line = 13;
/** @type {number} */
var string = 14;
/** @type {number} */
var all = 15;
/** @type {number} */
var r = 16;
/** @type {number} */
var command = 17;
/** @type {number} */
var tag = 19;
/** @type {number} */
var object = 20;
/** @type {number} */
var delimiter = 21;
/** @type {number} */
var code = 23;
/** @type {number} */
var group = 24;
/** @type {number} */
var elem = 25;
/** @type {number} */
var date = 26;
/** @type {number} */
var v = 27;
/** @type {number} */
var end = 28;
/** @type {number} */
var val = 29;
/** @type {number} */
var host = 31;
/** @type {number} */
var title = 33;
/** @type {number} */
var parent = 34;
/** @type {number} */
var p = 35;
/** @type {number} */
var size = 36;
/** @type {number} */
var key = 38;
/** @type {number} */
var node = 39;
/** @type {number} */
var undefined = 41;
/** @type {number} */
var event = 42;
/** @type {number} */
var action = 43;
/** @type {number} */
var h = 44;
/** @type {number} */
var none = 45;
/** @type {!Array} */
var types = [2, 3, 4, 5, 7, 8, 10, 13, 14, 15, 16, 17, 19, 20, 21, 23, 24, 25, 26, 27, 28, 29, 31, 33, 34, 35, 36, 38, 39, 41, 42, 43, 44, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
/** @type {!Array} */
var theCache = [2, 3, 4, 5, 7, 0, 11, 13, 0, 0, 16, 0, 19, 20, 21, 23, 24, 4, 26, 12, 0, 0, 31, 33, 34, 0, 36, 0, 39, 41, 42, 0, 44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
/** @type {!Array} */
var utilReqPaths = [2, 3, 4, 5, 7, 8, 11, 13, 0, 15, 16, 0, 19, 20, 21, 23, 24, 0, 26, 27, 0, 0, 31, 33, 34, 0, 36, 0, 39, 41, 42, 0, 44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
/** @type {!Array} */
var assetLocationTranslation = [2, 3, 4, 5, 7, 8, 10, 0, 14, 0, 16, 17, 19, 20, 21, 23, 0, 25, 26, 27, 28, 29, 31, 0, 34, 0, 36, 38, 39, 0, 0, 43, 44, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
/** @type {!Array} */
var settings = [[0], [6316128], [15908203], [4210943], [16728128], [9486400], [8409120], [11567184], [8421631], [11575440], [13684991], [16777215], [14737632], [16728224], [9465872], [16750950], [8400928], [16777164], [16769198], [8421504], [16737843], [8388736], [16769198], [4486912], [12615872], [16752672], [13408665], [14737632], [16776992], [4210752], [16769198], [6710784], [16769198], [13369344], [13434624], [47872], [16777215], [3381759], [65793], [8417360], [16769198], [11184810], [16763955], 
					 [4469538], [13421772], [13107, 0, 15908203, 4210943, 16728128, 9486400, 8409120, 11567184, 8421631, 0, 13684991, 16777215, 14737632, 16728224, 9465872, 16750950, 8400928, 16777164, 0, 8421504, 16737843, 8388736, 0, 4486912, 12615872, 16752672, 13408665, 14737632, 16776992, 4210752, 0, 6710784, 0, 13369344, 13434624, 47872, 16777215, 3381759, 65793, 8417360, 0, 11184810, 16763955, 4469538, 13421772, 0]];
/** @type {!Array} */
var channels = Array(settings.length);
/** @type {!Array} */
var cell = [0, 0, 0, 0, 5E3, 500, 500, 0, 0, 0, -1E3, -500, 0, 0, 0, 0, 0, 0, 0, 0, 1E4, 0, 0, 0, 1500, 4E3, 500, 0, 2E3, 0, 0, 0, 0, 5500, 0, 500, 0, 0, 0, 2E3, 0, 0, 3E3, 0, 0, 0];
/** @type {number} */
var element = -5;
/** @type {number} */
var temp = -4;
var mockObject = new e;
/**
 * @param {number} a
 * @return {undefined}
 */
e.prototype.e = function(a) {
	var j;
	var i;
	var x;
	/** @type {number} */
	step = 104;
	/** @type {number} */
	cols = 79;
	/** @type {number} */
	width = 4;
	/** @type {number} */
	len = step * cols;
	/** @type {number} */
	j = 0;
	for (; j < len; j++) {
		cb(values[j], 0, 0);
	}
	/** @type {number} */
	j = 0;
	for (; j < len; j++) {
		cb(res[j], 0, 0);
	}
	/** @type {number} */
	j = 0;
	for (; j < len; j++) {
		/** @type {number} */
		buf[j] = 0;
	}
	/** @type {number} */
	j = 0;
	for (; j < len; j++) {
		/** @type {number} */
		view[j] = 0;
	}
	/** @type {number} */
	x = i = t = 0;
	for (; x < cols; x++) {
		/** @type {number} */
		j = 0;
		for (; j < step; j++, i++) {
			/** @type {number} */
			nums[i] = j * width;
			/** @type {number} */
			dst[i] = x * width;
		}
	}
	/** @type {number} */
	j = 0;
	for (; j < len; j++) {
		/** @type {number} */
		out[j] = 0;
	}
	if (0 == a) {
		/** @type {number} */
		j = 0;
		/** @type {number} */
		i = 2 * step + 2;
		for (; j < step - 4; j++, i++) {
			/** @type {number} */
			out[i] = 1;
		}
		/** @type {number} */
		j = 0;
		/** @type {number} */
		i = step * (cols - 3) + 2;
		for (; j < step - 4; j++, i++) {
			/** @type {number} */
			out[i] = 1;
		}
		/** @type {number} */
		j = 0;
		/** @type {number} */
		i = 2 * step + 2;
		for (; j < cols - 4; j++, i = i + step) {
			/** @type {number} */
			out[i] = 1;
		}
		/** @type {number} */
		j = 0;
		/** @type {number} */
		i = 3 * step - 3;
		for (; j < cols - 4; j++, i = i + step) {
			/** @type {number} */
			out[i] = 1;
		}
	}
	/** @type {number} */
	j = 0;
	/** @type {number} */
	i = step + 1;
	for (; j < step - 2; j++, i++) {
		/** @type {number} */
		out[i] = -1;
	}
	/** @type {number} */
	j = 0;
	/** @type {number} */
	i = step * (cols - 2) + 1;
	for (; j < step - 2; j++, i++) {
		/** @type {number} */
		out[i] = -1;
	}
	/** @type {number} */
	j = 0;
	/** @type {number} */
	i = step + 1;
	for (; j < cols - 2; j++, i = i + step) {
		/** @type {number} */
		out[i] = -1;
	}
	/** @type {number} */
	j = 0;
	/** @type {number} */
	i = 2 * step - 2;
	for (; j < cols - 2; j++, i = i + step) {
		/** @type {number} */
		out[i] = -1;
	}
	/** @type {number} */
	i = j = 0;
	for (; j < step; j++, i++) {
		/** @type {number} */
		out[i] = -1;
	}
	/** @type {number} */
	j = 0;
	/** @type {number} */
	i = step * (cols - 1);
	for (; j < step; j++, i++) {
		/** @type {number} */
		out[i] = -1;
	}
	/** @type {number} */
	i = j = 0;
	for (; j < cols; j++, i = i + step) {
		/** @type {number} */
		out[i] = -1;
	}
	/** @type {number} */
	j = 0;
	/** @type {number} */
	i = step - 1;
	for (; j < cols; j++, i = i + step) {
		/** @type {number} */
		out[i] = -1;
	}
	/** @type {number} */
	value = 2 * width;
	/** @type {number} */
	y = 2 * width;
	/** @type {number} */
	total = value;
	/** @type {number} */
	g = y;
	cb(expected, 0, 0);
	/** @type {number} */
	k = 0;
	/** @type {number} */
	count = 4E4;
	/** @type {number} */
	i = 0;
	for (; i < 316 * length; i++) {
		/** @type {number} */
		obj[i] = element;
	}
	/** @type {number} */
	i = 0;
	for (; i < count; i++) {
		/** @type {number} */
		samples[i] = 0;
	}
	/** @type {number} */
	idx = 0;
	/** @type {number} */
	selector = 100;
	/** @type {number} */
	m = 0;
	/** @type {number} */
	model = 2E3;
	/** @type {number} */
	content = 0;
	/** @type {number} */
	ticksPerBeat = 5;
	/** @type {number} */
	w2 = ticksPerBeat / (ratio + ratio) * 2;
	/** @type {number} */
	to = 0;
	/** @type {number} */
	from = 50;
	/** @type {number} */
	stride = 28;
	/** @type {number} */
	i = 0;
	for (; i < from * stride; i++) {
		/** @type {number} */
		keys[i] = 0;
	}
	/** @type {number} */
	i = 0;
	for (; i < from; i++) {
		/** @type {number} */
		rows[i] = 0;
	}
	/** @type {number} */
	i = 0;
	for (; i < from; i++) {
		/** @type {number} */
		children[i] = 0;
	}
	/** @type {number} */
	i = 0;
	for (; i < from; i++) {
		/** @type {number} */
		lines[i] = 0;
	}
	/** @type {number} */
	i = 0;
	for (; i < from; i++) {
		/** @type {number} */
		list[i] = 0;
	}
	/** @type {number} */
	i = 0;
	for (; i < from; i++) {
		/** @type {number} */
		g_board[i] = 0;
	}
	/** @type {number} */
	_len = 50;
	/** @type {number} */
	i = 0;
	for (; i < _len; i++) {
		/** @type {number} */
		plugins[i] = 0;
	}
	/** @type {number} */
	i = 0;
	for (; i < _len; i++) {
		/** @type {number} */
		cache[i] = 0;
	}
	/** @type {number} */
	i = 0;
	for (; i < _len; i++) {
		/** @type {number} */
		states[i] = 0;
	}
	/** @type {number} */
	i = 0;
	for (; i < _len; i++) {
		/** @type {number} */
		data[i] = 0;
	}
	if (0 == a) {
		/** @type {number} */
		i = 8 * length + 8;
		/** @type {number} */
		x = 8;
		for (; 308 > x; x++, i = i + 16) {
			/** @type {number} */
			j = 8;
			for (; 408 > j; j++, i++) {
				/** @type {number} */
				a = (x >> 2) * step + (j >> 2);
				if (1 == out[a]) {
					/** @type {number} */
					obj[i] = -1;
				}
			}
		}
	}
	/** @type {number} */
	j = 309 * length - 1;
	for (; 0 <= j; j--) {
		/** @type {number} */
		buffer[j] = 0;
		/** @type {number} */
		sprites[j] = 0;
		/** @type {number} */
		elements[j] = 0;
	}
	/** @type {number} */
	z = 0;
};
/** @type {function(): undefined} */
msg.fff = e.prototype.move;
/**
 * @return {undefined}
 */
e.prototype.move = function() {
	var i;
	var k;
	var x;
	var a = new Vector;
	var v = new Vector;
	var f = new Vector;
	if (!extreme && 0 == evalID) {
		total = value;
		g = y;
		value = clamp(lat + 2 * width, 2 * width, width * (step - 2) - 1);
		y = clamp(lon + 2 * width, 2 * width, width * (cols - 2) - 1);
		if (0 < tileSize) {
			value = 2 * width + parseInt(time) + (lat >> tileSize);
			y = 2 * width + parseInt(delta) + (lon >> tileSize);
			value = clamp(value, 2 * width, width * (step - 2) - 1);
			y = clamp(y, 2 * width, width * (cols - 2) - 1);
		}
		if (hasToggledVideo) {
			total = value;
			g = y;
		}
		if (1 == bx1) {
			if (hasToggledVideo || hasToggledAudio) {
				amount = value;
				x1 = y;
			} else {
				if (rx || ry) {
					total = amount;
					g = x1;
				}
			}
		} else {
			if (2 == bx1) {
				if (hasToggledVideo || hasToggledAudio) {
					/** @type {number} */
					Ca = 0;
				} else {
					if (target || cmp) {
						if (0 == Ca) {
							if (abs(value - total) > abs(y - g)) {
								/** @type {number} */
								Ca = 1;
							} else {
								if (abs(value - total) < abs(y - g)) {
									/** @type {number} */
									Ca = 2;
								}
							}
						}
					} else {
						if (rx || ry) {
							/** @type {number} */
							Ca = 0;
						}
					}
				}
				if (1 == Ca) {
					y = g;
				} else {
					if (2 == Ca) {
						value = total;
					}
				}
			}
		}
		cb(a, value, y);
		cb(expected, total - 5 * expected.x, g - 5 * expected.y);
		var options = expected;
		/** @type {number} */
		var j = 5;
		/** @type {number} */
		k = i = 0.5;
		equals(scale, a, options);
		/** @type {number} */
		j = j - get(scale);
		/** @type {number} */
		i = i * j;
		/** @type {number} */
		k = k * j;
		a.x += scale.x * i;
		a.y += scale.y * i;
		options.x -= scale.x * k;
		options.y -= scale.y * k;
		equals(expected, a, expected);
		get(expected);
		transform(this, 0);
		transform(this, 1);
		if (hasToggledVideo || hasToggledAudio) {
			z = clamp(z + 1, 0, 4095);
		}
	}
	/** @type {!Array} */
	options = [1, 2, 4, 8];
	/** @type {number} */
	j = 0;
	for (; j < options[type]; j++) {
		/** @type {number} */
		i = k = 0;
		for (; i < len; i++) {
			if (0 == out[i]) {
				k++;
			}
		}
		if (0 < k) {
			/** @type {number} */
			t = t / k;
			/** @type {number} */
			i = 0;
			for (; i < len; i++) {
				if (0 == out[i]) {
					buf[i] += t;
				}
			}
			/** @type {number} */
			t = 0;
		}
		if (1 == gasSum && !(historyInstance && 0 == evalID && box[10] | box[13])) {
			break;
		}
		/** @type {number} */
		i = 0;
		for (; i < len; i++) {
			res[i].set(values[i]);
		}
		/** @type {number} */
		i = 2 * step + 2;
		/** @type {number} */
		x = 2;
		for (; x < cols - 2; x++, i = i + 4) {
			/** @type {number} */
			k = 2;
			for (; k < step - 2; k++, i++) {
				if (1 != out[i]) {
					a.set(values[i]);
					var c = get(a);
					if (0 != c) {
						var r = abs(a.x);
						var l = abs(a.y);
						/** @type {number} */
						var n = r / (r + l) * c * 0.5;
						/** @type {number} */
						c = l / (r + l) * c * 0.5;
						push(v, a, n);
						push(f, a, c);
						/** @type {number} */
						var j = 0 > a.x ? -1 : 1;
						var offset = 0 > a.y ? -step : step;
						if (r > l) {
							if (0 >= out[i + j]) {
								res[i].sub(v);
								res[i + j].add(v);
								buf[i + j] += n;
								buf[i] -= n;
							} else {
								res[i].sub(v);
								res[i].sub(v);
							}
							if (0 >= out[i + j + offset]) {
								res[i].sub(f);
								res[i + j + offset].add(f);
								buf[i] -= c;
								buf[i + j + offset] += c;
							} else {
								res[i].sub(f);
								res[i].sub(f);
							}
						} else {
							if (0 >= out[i + offset]) {
								res[i].sub(f);
								res[i + offset].add(f);
								buf[i] -= c;
								buf[i + offset] += c;
							} else {
								res[i].sub(f);
								res[i].sub(f);
							}
							if (0 >= out[i + offset + j]) {
								res[i].sub(v);
								res[i + offset + j].add(v);
								buf[i] -= n;
								buf[i + offset + j] += n;
							} else {
								res[i].sub(v);
								res[i].sub(v);
							}
						}
					}
				}
			}
		}
		/** @type {number} */
		i = 0;
		for (; i < len; i++) {
			/** @type {number} */
			view[i] = buf[i];
		}
		/** @type {number} */
		i = 2 * step + 2;
		/** @type {number} */
		r = -1 - step;
		/** @type {number} */
		l = 1 - step;
		n = -1 + step;
		c = 1 + step;
		/** @type {number} */
		x = 2;
		for (; x < cols - 2; x++, i = i + 4) {
			/** @type {number} */
			k = 2;
			for (; k < step - 2; k++, i++) {
				if (1 != out[i]) {
					if (0 >= out[i - 1]) {
						res[i].x -= 0.0625 * (buf[i] - buf[i - 1]);
						view[i] -= 0.0625 * (buf[i] - buf[i - 1]);
					}
					if (0 >= out[i + 1]) {
						res[i].x += 0.0625 * (buf[i] - buf[i + 1]);
						view[i] -= 0.0625 * (buf[i] - buf[i + 1]);
					}
					if (0 >= out[i - step]) {
						res[i].y -= 0.0625 * (buf[i] - buf[i - step]);
						view[i] -= 0.0625 * (buf[i] - buf[i - step]);
					}
					if (0 >= out[i + step]) {
						res[i].y += 0.0625 * (buf[i] - buf[i + step]);
						view[i] -= 0.0625 * (buf[i] - buf[i + step]);
					}
					if (0 >= out[i + r]) {
						res[i].x -= 0.044194173 * (buf[i] - buf[i + r]);
						res[i].y -= 0.044194173 * (buf[i] - buf[i + r]);
						view[i] -= 0.044194173 * (buf[i] - buf[i + r]);
					}
					if (0 >= out[i + l]) {
						res[i].x += 0.044194173 * (buf[i] - buf[i + l]);
						res[i].y -= 0.044194173 * (buf[i] - buf[i + l]);
						view[i] -= 0.044194173 * (buf[i] - buf[i + l]);
					}
					if (0 >= out[i + n]) {
						res[i].x -= 0.044194173 * (buf[i] - buf[i + n]);
						res[i].y += 0.044194173 * (buf[i] - buf[i + n]);
						view[i] -= 0.044194173 * (buf[i] - buf[i + n]);
					}
					if (0 >= out[i + c]) {
						res[i].x += 0.044194173 * (buf[i] - buf[i + c]);
						res[i].y += 0.044194173 * (buf[i] - buf[i + c]);
						view[i] -= 0.044194173 * (buf[i] - buf[i + c]);
					}
				}
			}
		}
		/** @type {number} */
		i = 0;
		for (; i < len; i++) {
			if (-1 != out[i]) {
				values[i].set(res[i]);
				/** @type {number} */
				buf[i] = view[i];
			} else {
				/** @type {number} */
				buf[i] = 0;
				cb(values[i], 0, 0);
			}
		}
		this.B();
		this.I();
		this.r();
		this.w();
		this.t();
	}
};
/** @type {function(): undefined} */
msg.fff = e.prototype.a;
/**
 * @return {undefined}
 */
e.prototype.a = function() {
	var i;
	var k;
	var n;
	var x;
	var index;
	var d;
	var e;
	var p;
	var j;
	index = new Vector;
	if (0 == i1) {
		/** @type {number} */
		i = 308 * length;
		for (; 0 <= i; i--) {
			/** @type {number} */
			pixels[i] = -1 == obj[i] ? 6316128 : 0;
		}
	} else {
		if (1 == i1 || 2 == i1) {
			/** @type {number} */
			i = 2 * step + 2;
			/** @type {number} */
			x = 2;
			for (; 77 > x; x++, i = i + 4) {
				/** @type {number} */
				n = 2;
				for (; 102 > n; n++, i++) {
					if (1 == out[i]) {
						drawLine(nums[i], dst[i], width, width, 6316128);
					} else {
						/** @type {number} */
						p = e = 0;
						if (0 < buf[i]) {
							e = parseInt(min(48 * buf[i], 96));
						}
						if (0 > buf[i]) {
							p = parseInt(min(48 * -buf[i], 96));
						}
						drawLine(nums[i], dst[i], width, width, e << 8 | p);
					}
				}
			}
			if (2 == i1) {
				var y;
				/** @type {number} */
				i = 0;
				for (; i < len; i++) {
					if (0 == out[i]) {
						index.set(values[i]);
						y = get(index);
						if (!(0.2 > y)) {
							/** @type {number} */
							k = nums[i] + 2;
							/** @type {number} */
							j = dst[i] + 2;
							if (8 < y) {
								/** @type {number} */
								y = 8;
							}
							d = parseInt(min(48 * y, 96));
							add(k + index.x * y * 10, j + index.y * y * 10, k, j, d << 16);
						}
					}
				}
			}
		} else {
			if (3 == i1) {
				/** @type {number} */
				i = 308 * length;
				for (; 3328 <= i; i--) {
					if (-1 == obj[i]) {
						/** @type {number} */
						pixels[i] = 6316128;
					} else {
						/** @type {number} */
						d = 230 * (pixels[i] >> 16 & 255) >> 8;
						/** @type {number} */
						e = 230 * (pixels[i] >> 8 & 255) >> 8;
						/** @type {number} */
						p = 230 * (pixels[i] & 255) >> 8;
						/** @type {number} */
						pixels[i] = d << 16 | e << 8 | p;
					}
				}
			} else {
				if (4 == i1) {
					/** @type {number} */
					x = 8;
					for (; 308 > x; x++) {
						/** @type {number} */
						index = x * length + 8;
						/** @type {number} */
						n = 8;
						for (; 407 > n; n++, index++) {
							/** @type {number} */
							d = (pixels[index] >> 16 & 255) + (pixels[index + 1] >> 16 & 255) >> 1;
							/** @type {number} */
							e = (pixels[index] >> 8 & 255) + (pixels[index + 1] >> 8 & 255) >> 1;
							/** @type {number} */
							p = (pixels[index] & 255) + (pixels[index + 1] & 255) >> 1;
							/** @type {number} */
							pixels[index] = d << 16 | e << 8 | p;
						}
						/** @type {number} */
						index = x * length + 407;
						/** @type {number} */
						n = 407;
						for (; 8 < n; n--, index--) {
							/** @type {number} */
							d = (pixels[index] >> 16 & 255) + (pixels[index - 1] >> 16 & 255) >> 1;
							/** @type {number} */
							e = (pixels[index] >> 8 & 255) + (pixels[index - 1] >> 8 & 255) >> 1;
							/** @type {number} */
							p = (pixels[index] & 255) + (pixels[index - 1] & 255) >> 1;
							/** @type {number} */
							pixels[index] = d << 16 | e << 8 | p;
						}
					}
					/** @type {number} */
					n = 8;
					for (; 408 > n; n++) {
						/** @type {number} */
						index = 8 * length + n;
						/** @type {number} */
						x = 8;
						for (; 307 > x; x++, index = index + length) {
							/** @type {number} */
							d = (pixels[index] >> 16 & 255) + (pixels[index + length] >> 16 & 255) >> 1;
							/** @type {number} */
							e = (pixels[index] >> 8 & 255) + (pixels[index + length] >> 8 & 255) >> 1;
							/** @type {number} */
							p = (pixels[index] & 255) + (pixels[index + length] & 255) >> 1;
							/** @type {number} */
							pixels[index] = d << 16 | e << 8 | p;
						}
						/** @type {number} */
						index = 307 * length + n;
						/** @type {number} */
						x = 307;
						for (; 8 < x; x--, index = index - length) {
							/** @type {number} */
							d = (pixels[index] >> 16 & 255) + (pixels[index - length] >> 16 & 255) >> 1;
							/** @type {number} */
							e = (pixels[index] >> 8 & 255) + (pixels[index - length] >> 8 & 255) >> 1;
							/** @type {number} */
							p = (pixels[index] & 255) + (pixels[index - length] & 255) >> 1;
							/** @type {number} */
							pixels[index] = d << 16 | e << 8 | p;
						}
					}
					/** @type {number} */
					i = 308 * length;
					for (; 0 <= i; i--) {
						if (-1 == obj[i]) {
							/** @type {number} */
							pixels[i] = 6316128;
						}
					}
				} else {
					if (5 == i1) {
						/** @type {number} */
						n = 309 * length;
						/** @type {number} */
						i = 0;
						for (; i < n; i++) {
							/** @type {number} */
							buffer[i] = sprites[i] = elements[i] = 0;
						}
						/** @type {!Array} */
						d = [1, 1, 1, length - 3, 1, 1, 1, length - 3, 1, 1, 1, length - 3, 1, 1, 1, length - 3];
						var a;
						/** @type {number} */
						index = 2 * step + 2;
						/** @type {number} */
						x = 2;
						for (; x < cols - 2; x++, index = index + 4) {
							/** @type {number} */
							n = 2;
							for (; n < step - 2; n++, index++) {
								if (e = abs(values[index].x), i = abs(values[index].y), 0 != e || 0 != i) {
									/** @type {number} */
									p = 1 / (e + i);
									e = parseInt(e * p * 65535);
									p = parseInt(i * p * 65535);
									/** @type {number} */
									j = k = 0;
									if (0 > values[index].x) {
										/** @type {number} */
										k = -1;
									} else {
										if (0 < values[index].x) {
											/** @type {number} */
											k = 1;
										}
									}
									if (0 > values[index].y) {
										/** @type {number} */
										j = -length;
									} else {
										if (0 < values[index].y) {
											/** @type {number} */
											j = length;
										}
									}
									/** @type {number} */
									y = (x << 2) * length + (n << 2);
									/** @type {number} */
									i = 0;
									for (; 16 > i; i++) {
										/** @type {number} */
										a = pixels[y] >> 16 & 255;
										buffer[y + k] += a * e;
										buffer[y + j] += a * p;
										/** @type {number} */
										a = pixels[y] >> 8 & 255;
										sprites[y + k] += a * e;
										sprites[y + j] += a * p;
										/** @type {number} */
										a = pixels[y] & 255;
										elements[y + k] += a * e;
										elements[y + j] += a * p;
										y = y + d[i];
									}
								}
							}
						}
						/** @type {number} */
						index = 8 * length + 8;
						/** @type {number} */
						x = 8;
						for (; 308 > x; x++, index = index + 16) {
							/** @type {number} */
							n = 8;
							for (; 408 > n; n++, index++) {
								/** @type {number} */
								pixels[index] = -1 == obj[index] ? 6316128 : min(buffer[index] >> 16, 255) << 16 | min(sprites[index] >> 16, 255) << 8 | min(elements[index] >> 16, 255);
							}
						}
					} else {
						if (6 == i1) {
							/** @type {number} */
							i = 308 * length;
							for (; 3328 <= i; i--) {
								if (-1 == obj[i]) {
									/** @type {number} */
									pixels[i] = 6316128;
								} else {
									/** @type {number} */
									d = 220 * (pixels[i] >> 16 & 255) >> 8;
									/** @type {number} */
									e = 220 * (pixels[i] >> 8 & 255) >> 8;
									/** @type {number} */
									p = 220 * (pixels[i] & 255) >> 8;
									/** @type {number} */
									pixels[i] = d << 16 | e << 8 | p;
								}
							}
						} else {
							if (7 == i1) {
								/** @type {number} */
								i = 308 * length;
								for (; 2912 <= i; i--) {
									if (-1 == obj[i]) {
										/** @type {number} */
										pixels[i] = 6316128;
									} else {
										if (-2 == obj[i]) {
											/** @type {number} */
											pixels[i] = 0;
										} else {
											if (obj[i] == temp) {
												/** @type {number} */
												pixels[i] = 8421631;
											} else {
												if (obj[i] == element) {
													pixels[i] = 0 <= obj[i + 1] ? settings[args[obj[i + 1]]][0] : 0 <= obj[i - 1] ? settings[args[obj[i - 1]]][0] : 0 <= obj[i + length] ? settings[args[obj[i + length]]][0] : 0 <= obj[i - length] ? settings[args[obj[i - length]]][0] : 0 <= obj[i + 
																																																																																													 length + 1] ? settings[args[obj[i + length + 1]]][0] : 0 <= obj[i + length - 1] ? settings[args[obj[i + length - 1]]][0] : 0 <= obj[i - length + 1] ? settings[args[obj[i - length + 1]]][0] : 0 <= obj[i - length - 1] ? settings[args[obj[i - length - 1]]][0] : 0;
												} else {
													if (0 <= obj[i]) {
														pixels[i] = settings[args[obj[i]]][0];
													}
												}
											}
										}
									}
								}
								/** @type {number} */
								i = 308 * length;
								for (; 3328 <= i; i--) {
									if (0 == pixels[i] >>> 0) {
										if (0 != pixels[i + 1] >>> 0 && 15658734 != pixels[i + 1] >>> 0) {
											/** @type {number} */
											pixels[i] = 15658734;
										} else {
											if (0 != pixels[i - 1] >>> 0 && 15658734 != pixels[i - 1] >>> 0) {
												/** @type {number} */
												pixels[i] = 15658734;
											} else {
												if (0 != pixels[i + length] >>> 0 && 15658734 != pixels[i + length] >>> 0) {
													/** @type {number} */
													pixels[i] = 15658734;
												} else {
													if (0 != pixels[i - length] >>> 0 && 15658734 != pixels[i - length] >>> 0) {
														/** @type {number} */
														pixels[i] = 15658734;
													}
												}
											}
										}
									}
								}
							} else {
								if (8 == i1) {
									/** @type {number} */
									i = 308 * length;
									for (; 0 <= i; i--) {
										/** @type {number} */
										pixels[i] = -1 == obj[i] ? 6316128 : 0;
									}
									/** @type {number} */
									i = 2 * step + 2;
									/** @type {number} */
									x = 2;
									for (; 77 > x; x++, i = i + 4) {
										/** @type {number} */
										n = 2;
										for (; 102 > n; n++, i++) {
											if (0 == out[i]) {
												index.set(values[i]);
												y = expect(index);
												if (!(0.2 > y)) {
													if (2 < y) {
														/** @type {number} */
														y = 2;
													}
													e = parseInt(min(48 * y, 96));
													/** @type {number} */
													d = 0;
													if (0 < buf[i]) {
														d = parseInt(min(48 * buf[i] * y, 96));
													}
													/** @type {number} */
													p = 0;
													if (0 > buf[i]) {
														p = parseInt(min(48 * -buf[i] * y, 96));
													}
													/** @type {number} */
													k = nums[i] + 5 * values[i].x;
													/** @type {number} */
													j = dst[i] + 5 * values[i].y;
													/** @type {number} */
													y = nums[i + 1] + 5 * values[i + 1].x;
													/** @type {number} */
													a = dst[i + 1] + 5 * values[i + 1].y;
													add(k, j, y, a, d << 16 | e << 8 | p);
													/** @type {number} */
													y = nums[i + step] + 5 * values[i + step].x;
													/** @type {number} */
													a = dst[i + step] + 5 * values[i + step].y;
													add(k, j, y, a, d << 16 | e << 8 | p);
												}
											}
										}
									}
								} else {
									if (9 == i1) {
										/** @type {number} */
										i = 2 * step + 2;
										/** @type {number} */
										x = 2;
										for (; 77 > x; x++, i = i + 4) {
											/** @type {number} */
											n = 2;
											for (; 102 > n; n++, i++) {
												if (1 == out[i]) {
													drawLine(nums[i], dst[i], width, width, 6316128);
												} else {
													/** @type {number} */
													d = 0;
													if (0 < buf[i]) {
														d = parseInt(min(48 * buf[i], 72));
													}
													if (0 > buf[i]) {
														d = parseInt(min(48 * -buf[i], 24));
													}
													drawLine(nums[i], dst[i], width, width, d << 16 | d << 8 | d);
												}
											}
										}
									} else {
										if (10 == i1) {
											/** @type {!Array} */
											y = [0, 1, 2, 3, length + 0, length + 1, length + 2, length + 3, 2 * length + 0, 2 * length + 1, 2 * length + 2, 2 * length + 3, 3 * length + 0, 3 * length + 1, 3 * length + 2, 3 * length + 3];
											/** @type {number} */
											i = 2 * step + 2;
											/** @type {number} */
											x = 2;
											for (; 77 > x; x++, i = i + 4) {
												/** @type {number} */
												n = 2;
												for (; 102 > n; n++, i++) {
													if (1 == out[i]) {
														drawLine(nums[i], dst[i], width, width, 6316128);
													} else {
														if (j = 256 - parseInt(min(abs(12 * buf[i]), 32)), 256 != j) {
															/** @type {number} */
															index = (x << 2) * length + (n << 2);
															/** @type {number} */
															k = 0;
															for (; 16 > k; k++) {
																/** @type {number} */
																d = (pixels[index + y[k]] >> 16 & 255) * j >> 8;
																/** @type {number} */
																e = (pixels[index + y[k]] >> 8 & 255) * j >> 8;
																/** @type {number} */
																p = (pixels[index + y[k]] & 255) * j >> 8;
																/** @type {number} */
																pixels[index + y[k]] = d << 16 | e << 8 | p;
															}
														}
													}
												}
											}
										} else {
											if (11 == i1) {
												/** @type {number} */
												i = 308 * length;
												for (; 0 <= i; i--) {
													buffer[i] = 0 > obj[i] ? parseInt(8 * buffer[i] / 9) : args[obj[i]] == options ? 25500 : args[obj[i]] == object ? 25500 : args[obj[i]] == elem ? 255E3 : args[obj[i]] == end ? 255E3 : args[obj[i]] == title ? 25500 : args[obj[i]] == event ? 
														25500 : parseInt(8 * buffer[i] / 9);
												}
												/** @type {number} */
												i = 308 * length;
												for (; 0 <= i; i--) {
													/** @type {number} */
													pixels[i] = -1 == obj[i] ? 6316128 : 0;
												}
											} else {
												if (12 == i1) {
													/** @type {number} */
													i = 0;
													for (; i < k; i++) {
														buffer[result[i]] = cell[args[i]];
													}
													/** @type {number} */
													x = 8;
													for (; 308 > x; x++) {
														/** @type {number} */
														index = x * length + 8;
														/** @type {number} */
														n = 8;
														for (; 407 > n; n++, index++) {
															buffer[index] = buffer[index + 1] = parseInt((buffer[index] + buffer[index + 1]) / 2);
														}
														/** @type {number} */
														n = 407;
														for (; 8 < n; n--, index--) {
															buffer[index] = buffer[index - 1] = parseInt((buffer[index] + buffer[index - 1]) / 2);
														}
													}
													/** @type {number} */
													n = 8;
													for (; 408 > n; n++) {
														/** @type {number} */
														index = 8 * length + n;
														/** @type {number} */
														x = 8;
														for (; 307 > x; x++, index = index + length) {
															buffer[index] = buffer[index + length] = parseInt((buffer[index] + buffer[index + length]) / 2);
														}
														/** @type {number} */
														x = 307;
														for (; 8 < x; x--, index = index - length) {
															buffer[index] = buffer[index - length] = parseInt((buffer[index] + buffer[index - length]) / 2);
														}
													}
													/** @type {number} */
													i = 308 * length;
													for (; 0 <= i; i--) {
														n = buffer[i];
														if (0 > n) {
															/** @type {number} */
															d = 128 * -n >> 10;
															if (255 < d) {
																/** @type {number} */
																d = 255;
															}
															/** @type {number} */
															e = 0;
															/** @type {number} */
															p = 255 * -n >> 10;
															if (255 < p) {
																/** @type {number} */
																p = 255;
															}
														} else {
															if (1024 > n) {
																/** @type {number} */
																e = d = 0;
																/** @type {number} */
																p = 255 * n >> 10;
															} else {
																if (2048 > n) {
																	/** @type {number} */
																	d = 0;
																	/** @type {number} */
																	e = 255 * (n - 1024) >> 10;
																	/** @type {number} */
																	p = 255;
																} else {
																	if (3072 > n) {
																		/** @type {number} */
																		d = 0;
																		/** @type {number} */
																		e = 255;
																		/** @type {number} */
																		p = 255 - (255 * (n - 2048) >> 10);
																	} else {
																		if (4096 > n) {
																			/** @type {number} */
																			d = 255 * (n - 3072) >> 10;
																			/** @type {number} */
																			e = 255;
																			/** @type {number} */
																			p = 0;
																		} else {
																			if (6144 > n) {
																				/** @type {number} */
																				d = 255;
																				/** @type {number} */
																				e = 255 - (255 * (n - 4096) >> 11);
																				/** @type {number} */
																				p = 0;
																			} else {
																				/** @type {number} */
																				d = 255;
																				/** @type {number} */
																				e = 255 * (n - 6144) >> 11;
																				if (255 < e) {
																					/** @type {number} */
																					e = 255;
																				}
																				/** @type {number} */
																				p = 255 * (n - 6144) >> 11;
																				if (255 < p) {
																					/** @type {number} */
																					p = 255;
																				}
																			}
																		}
																	}
																}
															}
														}
														/** @type {number} */
														pixels[i] = d << 16 | e << 8 | p;
													}
													/** @type {number} */
													i = 308 * length;
													for (; 0 <= i; i--) {
														if (-1 == obj[i]) {
															/** @type {number} */
															pixels[i] = 6316128;
														}
													}
												} else {
													if (13 == i1) {
														/** @type {number} */
														i = 308 * length;
														for (; 3328 <= i; i--) {
															if (-1 == obj[i]) {
																/** @type {number} */
																pixels[i] = 0;
															} else {
																if (obj[i] == element) {
																	/** @type {number} */
																	d = 255 - (255 - (pixels[i] >> 16 & 255) >> 1);
																	/** @type {number} */
																	e = 255 - (255 - (pixels[i] >> 8 & 255) >> 1);
																	/** @type {number} */
																	p = 255 - (255 - (pixels[i] & 255) >> 1);
																	/** @type {number} */
																	pixels[i] = d << 16 | e << 8 | p;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (1 < err) {
		/** @type {!Array} */
		d = [0, 0, 100, 50, 25, 16, 8, 4];
		/** @type {number} */
		i = 0;
		for (; 400 > i; i = i + d[err]) {
			/** @type {number} */
			x = 0;
			index = 8 * length + i + 8;
			for (; 300 > x; x++, index = index + length) {
				if (6316128 != pixels[index]) {
					/** @type {number} */
					pixels[index] = 4210752;
				}
			}
		}
		/** @type {number} */
		i = 0;
		for (; 300 > i; i = i + d[err]) {
			/** @type {number} */
			n = 0;
			/** @type {number} */
			index = (i + 8) * length + 8;
			for (; 400 > n; n++, index++) {
				if (6316128 != pixels[index]) {
					/** @type {number} */
					pixels[index] = 4210752;
				}
			}
		}
	}
	if (0 < err) {
		/** @type {number} */
		x = 0;
		/** @type {number} */
		index = 8 * length + 208;
		for (; 300 > x; x++, index = index + length) {
			if (6316128 != pixels[index]) {
				/** @type {number} */
				pixels[index] = 4194304;
			}
		}
		/** @type {number} */
		n = 0;
		/** @type {number} */
		index = 158 * length + 8;
		for (; 400 > n; n++, index++) {
			if (6316128 != pixels[index]) {
				/** @type {number} */
				pixels[index] = 4194304;
			}
		}
	}
	this.A();
	this.H();
	this.q();
	this.v();
	this.s();
	if (11 == i1) {
		/** @type {number} */
		x = 8;
		for (; 308 > x; x++) {
			/** @type {number} */
			index = x * length + 8;
			/** @type {number} */
			n = 8;
			for (; 407 > n; n++, index++) {
				/** @type {number} */
				buffer[index] = buffer[index] + buffer[index + 1] >> 1;
			}
			/** @type {number} */
			n = 407;
			for (; 8 < n; n--, index--) {
				/** @type {number} */
				buffer[index] = buffer[index] + buffer[index - 1] >> 1;
			}
		}
		/** @type {number} */
		n = 8;
		for (; 408 > n; n++) {
			/** @type {number} */
			index = 8 * length + n;
			/** @type {number} */
			x = 8;
			for (; 307 > x; x++, index = index + length) {
				/** @type {number} */
				buffer[index] = buffer[index] + buffer[index + length] >> 1;
			}
			/** @type {number} */
			x = 307;
			for (; 8 < x; x--, index = index - length) {
				/** @type {number} */
				buffer[index] = buffer[index] + buffer[index - length] >> 1;
			}
		}
		/** @type {number} */
		i = 308 * length;
		for (; 0 <= i; i--) {
			if (1 > buffer[i]) {
				/** @type {number} */
				pixels[i] = 0;
			} else {
				j = min(buffer[i], 255);
				/** @type {number} */
				d = (pixels[i] >> 16 & 255) * j >> 8;
				/** @type {number} */
				e = (pixels[i] >> 8 & 255) * j >> 8;
				/** @type {number} */
				p = (pixels[i] & 255) * j >> 8;
				/** @type {number} */
				pixels[i] = d << 16 | e << 8 | p;
			}
		}
	}
	i = new Vector;
	if (!extreme && 0 == evalID) {
		if (50 == url || 51 == url || 52 == url || 50 == l || 51 == l || 52 == l) {
			/** @type {number} */
			x = (g >> 2) - 1 - parseInt(w / 2);
			/** @type {!Array} */
			index = [[], [1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4], [1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4], [1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
																																																																																																																																																										 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4], [1, 1, 1, 1, 1, 1, 
																																																																																																																																																																																																																																																																																																																								  1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 
																																																																																																																																																																																																																																																																																																																																																																																																																															 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 3, 
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																														3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																				  4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4]];
			d = w;
			/** @type {number} */
			n = ((total >> 2) - 1 - parseInt(w / 2) + [0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4][d]) * width;
			/** @type {number} */
			x = (x + [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1][d]) * width;
			/** @type {number} */
			e = 0;
			for (; e < index[d].length; e++) {
				p = clamp(x, 0, 308) * length + clamp(n, 0, length - 1);
				/** @type {number} */
				pixels[p] = 12582912;
				if (1 == index[d][e]) {
					n++;
				}
				if (2 == index[d][e]) {
					x++;
				}
				if (3 == index[d][e]) {
					n--;
				}
				if (4 == index[d][e]) {
					x--;
				}
			}
		}
		if (5 == url || 5 == l || 40 == url || 40 == l || 23 == url || 23 == l) {
			push(i, expected, 30);
			add(value + i.x, y + i.y, value, y, 16711680);
		}
		if (53 == url || 53 == l) {
			if (0 == COLON) {
				if (53 == url && target || 53 == l && cmp) {
					add(y1, c, y2, c, 16761024);
					add(y1, b, y2, b, 16761024);
					add(y1, c, y1, b, 16761024);
					add(y2, c, y2, b, 16761024);
				}
			} else {
				/** @type {number} */
				n = value - parseInt((y2 - y1) / 2);
				/** @type {number} */
				x = y - parseInt((b - c) / 2);
				/** @type {number} */
				i = y2 - y1;
				/** @type {number} */
				index = b - c;
				add(n, x, n + i, x, 12632319);
				add(n, x + index, n + i, x + index, 12632319);
				add(n, x, n, x + index, 12632319);
				add(n + i, x, n + i, x + index, 12632319);
			}
		}
		if (54 == url || 54 == l) {
			add(a, d, a, d + 13, 12582912);
			add(a, d, a + 200, d, 12582912);
			add(a, d + 13, a + 200, d + 13, 12582912);
		}
		if (1 == bx1 && (target && (34 > url || 50 == url || 51 == url || 52 == url) || cmp && (34 > l || 50 == l || 51 == l || 52 == l))) {
			add(amount, x1, value, y, 16711680);
		}
	}
};
/** @type {number} */
var k = 0;
/** @type {number} */
var count = 4E4;
/** @type {!Array} */
var params = Array(count);
/** @type {!Array} */
var items = Array(count);
/** @type {!Int32Array} */
var args = new Int32Array(count);
/** @type {!Int32Array} */
var arr = new Int32Array(count);
/** @type {!Uint32Array} */
var map = new Uint32Array(count);
/** @type {!Int32Array} */
var obj = new Int32Array(316 * length);
/** @type {!Int32Array} */
var result = new Int32Array(count);
/** @type {!Int32Array} */
var samples = new Int32Array(count);
/** @type {number} */
k = 0;
for (; k < count; k++) {
	params[k] = new Vector;
}
/** @type {number} */
k = 0;
for (; k < count; k++) {
	items[k] = new Vector;
}
/** @type {!Array} */
var topDomains = [1, -1, length, -length, length + 1, length - 1, -length + 1, -length - 1];
/** @type {!Array} */
var varWikidataTypes = [1, 1, 0, -1, -1, -1, 0, 1];
/** @type {!Array} */
var priorityToColor = [0, -1, -1, -1, 0, 1, 1, 1];
/** @type {!Array} */
var tags = [1, -length + 1, -length, -length - 1, -1, length - 1, length, length + 1];
/** @type {!Array} */
var langreverse = [0, 0, 0.2, 0, 0, 0.2, 0.7, 0.2, 0, 0, 0.8, 0.2, 0.2, 0, 0.2, 0.5, 0, 0.5, 0, 0.9, 0.2, 0, 0, 0, 0.3, 0, 0, 0, 0, 0.9, 0, 0.9, 0, 0, 0, 0.8, 0.2, 0, 0.9, 0.1, 0, 0.9, 0.9, 0.5, 0, 0.9];
/** @type {!Array} */
var illuminant = [0, 0, 0.2, 0, 0, 0.2, 0.7, 0.2, 0, 0, 1, 0.2, 0.2, 0, 0.2, 0.5, 0, 0.5, 0, 0.9, 0.2, 0, 0, 0, 0.3, 0, 0, 1, 0, 0.9, 0, 0.9, 0, 0, 0, 0.2, 0.2, 0, 0.5, 0.1, 0, 0.9, 0.9, 0.5, 0, 0.9];
/** @type {!Array} */
var c1 = [0, 0, 5, 40, 10, 5, 10, 10, 0, 0, 40, 10, 30, 10, 0, 10, 30, 100, 0, 20, 50, 10, 0, 100, 5, 10, 5, 30, 0, 10, 0, 10, 0, 5, 0, 10, 5, 40, 0, 10, 0, 20, 5, 50, 5, 0];
/** @type {!Array} */
var hash = [0, 0, 1, 2, 3, 1, 4, 1, 0, 0, 4, 1, 0, 1, 4, 1, 2, 4, 0, 1, 3, 1, 0, 2, 1, 3, 5, 2, 3, 4, 0, 1, 0, 3, 2, 4, 1, 2, 4, 5, 0, 2, 3, 4, 5, 4];
/** @type {function(): undefined} */
msg.fff = e.prototype.B;
/**
 * @return {undefined}
 */
e.prototype.B = function() {
	var i;
	var k = new Vector;
	var j;
	var id;
	var dx;
	var lx;
	/** @type {number} */
	i = 0;
	for (; i < idx; i++) {
		/** @type {number} */
		j = (tokens[i] - 16) * length + (times[i] - 16);
		/** @type {number} */
		lx = 0;
		for (; 32 > lx; lx++, j = j + (length - 32)) {
			/** @type {number} */
			dx = 0;
			for (; 32 > dx; dx++, j++) {
				if (-3 == obj[j]) {
					/** @type {number} */
					obj[j] = element;
				}
			}
		}
	}
	/** @type {number} */
	i = 0;
	for (; i < idx; i++) {
		/** @type {number} */
		j = (tokens[i] - 16) * length + (times[i] - 16);
		/** @type {number} */
		id = 32 * parseInt(rules[i]) * tmp.c;
		/** @type {number} */
		lx = 0;
		for (; 32 > lx; lx++, j = j + (length - 32)) {
			/** @type {number} */
			dx = 0;
			for (; 32 > dx; dx++, j++, id++) {
				if (0 == tmp.b[id] && obj[j] <= temp) {
					/** @type {number} */
					obj[j] = -3;
				}
			}
		}
	}
	/** @type {boolean} */
	j = true;
	if (extreme || 0 != evalID) {
		/** @type {boolean} */
		j = false;
	}
	/** @type {boolean} */
	id = 42 == url && hasToggledVideo || 42 == l && hasToggledAudio ? true : false;
	/** @type {boolean} */
	dx = 42 == url && target || 42 == l && cmp ? true : false;
	/** @type {number} */
	i = 0;
	for (; i < k; i++) {
		if (j) {
			if (0 == samples[i]) {
				if (id) {
					if (args[i] == id) {
						continue;
					}
					/** @type {number} */
					k.x = value - params[i].x;
					/** @type {number} */
					k.y = y - params[i].y;
					if (expect(k) < 4 * w) {
						/** @type {number} */
						samples[i] = 1;
					}
				}
			} else {
				if (dx) {
					items[i].x += 0.1 * (value - params[i].x);
					items[i].y += 0.1 * (y - params[i].y);
				} else {
					/** @type {number} */
					samples[i] = 0;
				}
			}
		}
		/** @type {number} */
		i = args[i] <= command ? i - this.C(i, k) : args[i] <= val ? i - this.D(i, k) : args[i] <= undefined ? i - this.F(i, k) : i - this.G(i, k);
	}
	if (0 == option) {
		/** @type {number} */
		i = 0;
		for (; i < k; i++) {
			if (8 > params[i].x) {
				call(i--);
			} else {
				if (408 <= params[i].x) {
					call(i--);
				} else {
					if (8 > params[i].y) {
						call(i--);
					} else {
						if (308 <= params[i].y) {
							call(i--);
						}
					}
				}
			}
		}
	} else {
		if (1 == option) {
			/** @type {number} */
			i = 0;
			for (; i < k; i++) {
				if (8 > params[i].x) {
					/** @type {number} */
					k = result[i] + 400;
					if (obj[k] <= temp && !(8 > params[i].y || 308 <= params[i].y)) {
						/** @type {number} */
						obj[result[i]] = element;
						params[i].x += 400;
						/** @type {number} */
						obj[k] = i;
						/** @type {number} */
						result[i] = k;
					} else {
						call(i--);
					}
				} else {
					if (408 <= params[i].x) {
						/** @type {number} */
						k = result[i] - 400;
						if (obj[k] <= temp && !(8 > params[i].y || 308 <= params[i].y)) {
							/** @type {number} */
							obj[result[i]] = element;
							params[i].x -= 400;
							/** @type {number} */
							obj[k] = i;
							/** @type {number} */
							result[i] = k;
						} else {
							call(i--);
						}
					} else {
						if (8 > params[i].y) {
							/** @type {number} */
							k = result[i] + 300 * length;
							if (obj[k] <= temp) {
								/** @type {number} */
								obj[result[i]] = element;
								params[i].y += 300;
								/** @type {number} */
								obj[k] = i;
								/** @type {number} */
								result[i] = k;
							} else {
								call(i--);
							}
						} else {
							if (308 <= params[i].y) {
								/** @type {number} */
								k = result[i] - 300 * length;
								if (obj[k] <= temp) {
									/** @type {number} */
									obj[result[i]] = element;
									params[i].y -= 300;
									/** @type {number} */
									obj[k] = i;
									/** @type {number} */
									result[i] = k;
								} else {
									call(i--);
								}
							}
						}
					}
				}
			}
		}
	}
};
/** @type {function(number, !Object): ?} */
msg.fff = e.prototype.C;
/**
 * @param {number} i
 * @param {!Object} item
 * @return {?}
 */
e.prototype.C = function(i, item) {
	var w;
	var x;
	var index;
	/** @type {number} */
	x = (params[i].y >> 2) * step + (params[i].x >> 2);
	/** @type {number} */
	index = result[i];
	if (args[i] != id) {
		/** @type {number} */
		obj[index] = element;
	}
	item.set(values[x]);
	if (args[i] == _) {
		item.y += clamp(0.01, 0.1);
		item.add(items[i]);
		parse(items[i], 0.7);
		done(i, item);
	} else {
		if (args[i] == name) {
			items[i].x += 0.2 * values[x].x;
			items[i].y += 0.2 * values[x].y;
			if (obj[index + length] != element) {
				if (obj[index - 1] == element) {
					items[i].x -= clamp(0.1, 0.2);
				}
				if (obj[index + 1] == element) {
					items[i].x += clamp(0.1, 0.2);
				}
			}
			items[i].x += clamp(-0.01, 0.01);
			items[i].y += clamp(0.01, 0.05);
			parse(items[i], 0.9);
			item.add(items[i]);
			index = done(i, item);
			x = Number(8);
			var j;
			j = 5 > x ? index - length : 6 > x ? index - 1 : 7 > x ? index + 1 : index + length;
			/** @type {number} */
			var key = obj[j];
			if (0 <= key) {
				if (7 > x && (1 == hash[args[key]] && args[key] != tag || args[key] == code || args[key] == v || 37 == args[key])) {
					if (10 > apply(100)) {
						iterator(i, key, index, j);
					}
				} else {
					if (args[key] == current) {
						if (50 > apply(100)) {
							/** @type {number} */
							args[i] = current;
						}
					} else {
						if (args[key] == none && 0 == map[key]) {
							return arr[key] = 4 | (5 > x ? 2 : 6 > x ? 1 : 7 > x ? 3 : 0), map[key] = name, call(i), 1;
						}
					}
				}
			}
		} else {
			if (args[i] == options) {
				if (2 == arr[i]) {
					parse(items[i], 0.8);
					item.add(items[i]);
				}
				parse(item, 0.2);
				if (0 == arr[i] || 2 == arr[i]) {
					var y = clamp(-0.01, -0.05);
					values[x].x += clamp(-0.02, 0.02);
					values[x].y += y;
					buf[x] += -y;
					/** @type {number} */
					t = t - -y;
				} else {
					if (1 == arr[i]) {
						y = clamp(-0.01, -0.05);
						buf[x] += -y;
						/** @type {number} */
						t = t - -y;
					}
				}
				index = done(i, item);
				index = index + (Number(5) - 2);
				index = index + (Number(5) - 2) * length;
				/** @type {number} */
				key = obj[index - length];
				if (0 <= key) {
					if (args[key] == _) {
						/** @type {number} */
						args[key] = options;
					} else {
						if (args[key] == name || 37 == args[key]) {
							return call(i), 1;
						}
						if (args[key] == number) {
							if (50 > apply(100)) {
								/** @type {number} */
								args[key] = options;
							}
						} else {
							if (11 == args[key]) {
								/** @type {number} */
								args[key] = name;
							} else {
								if (args[key] == group) {
									/** @type {number} */
									args[key] = options;
								} else {
									if (args[key] == p) {
										/** @type {number} */
										args[key] = options;
									}
								}
							}
						}
					}
				}
				/** @type {number} */
				x = 5;
				if (1 == arr[i]) {
					/** @type {number} */
					x = 20;
				}
				if (apply(100) < x) {
					return call(i), 1;
				}
			} else {
				if (args[i] == number) {
					if (0 == arr[i]) {
						item.y += clamp(0.01, 0.09);
						item.add(items[i]);
						parse(items[i], 0.8);
					} else {
						cb(item, 0, 0);
					}
					index = done(i, item);
					if (0 == arr[i] && (key = obj[index + length], 0 > key || args[key] != _ && 6 != args[key] && args[key] != p || 1E3 > beginHint[max] - k)) {
						return 0;
					}
					/** @type {number} */
					arr[i] = 1;
					/** @type {number} */
					x = ~~params[i].x + Number(3) - 1;
					/** @type {number} */
					y = ~~params[i].y - Number(1.5);
					/** @type {number} */
					j = y * length + x;
					if (obj[j] <= temp && (obj[j + length] <= temp && (index = x, j = y, obj[result[i]] = element, cb(params[i], index, j), result[i] = ~~j * length + ~~index, obj[result[i]] = i, callback(x, y + 1, 6)), 5 > apply(100))) {
						return call(i), 1;
					}
				} else {
					if (6 == args[i]) {
						if (item.set(items[i]), parse(items[i], 0.3), index = done(i, item), 0 == arr[i]) {
							if (index = index + (Number(5) - 2), index = index + (Number(7) - 3) * length, key = obj[index], 0 <= key) {
								if (args[key] == options || args[key] == object) {
									if (50 > apply(100)) {
										/** @type {number} */
										arr[i] = 1;
									}
								} else {
									if (args[key] == name) {
										if (1E3 > beginHint[max] - k) {
											return 0;
										}
										/** @type {number} */
										x = ~~params[i].x + Number(3) - 1;
										/** @type {number} */
										y = ~~params[i].y + Number(3) - 1;
										/** @type {number} */
										index = y * length + x;
										if (obj[index] <= temp && 10 > apply(100)) {
											callback(x, y, number);
										}
									}
								}
							}
						} else {
							if (1 == arr[i]) {
								/** @type {number} */
								x = ~~params[i].x + Number(3) - 1;
								/** @type {number} */
								y = ~~params[i].y + Number(3) - 1;
								/** @type {number} */
								index = y * length + x;
								/** @type {number} */
								key = obj[index];
								if (obj[index] <= temp) {
									if (30 > apply(100)) {
										index = callback(x, y, options);
										if (0 <= index) {
											/** @type {number} */
											arr[index] = 1;
										}
									}
								} else {
									if (0 <= key && args[key] == name) {
										/** @type {number} */
										arr[i] = 0;
										/** @type {number} */
										args[i] = _;
									}
								}
								if (5 > apply(1E3)) {
									/** @type {number} */
									args[i] = _;
								}
							}
						}
					} else {
						if (args[i] == message) {
							item.y += clamp(0.01, 0.2);
							item.add(items[i]);
							parse(items[i], 0.8);
							index = done(i, item);
							index = index + (Number(5) - 2);
							index = index + (Number(5) - 2) * length;
							/** @type {number} */
							key = obj[index];
							if (0 > key || 3 != hash[args[key]]) {
								return 0;
							}
							/** @type {number} */
							w = 10;
							/** @type {number} */
							var cx = params[i].x & 65524;
							/** @type {number} */
							var cy = params[i].y & 65524;
							var b = max(cx - w, width);
							x = max(cy - w, width);
							var old = min(cx + w, length - width - 1);
							var oldProto = min(cy + w, (cols - 1) * width - 1);
							y = x;
							for (; y <= oldProto; y++) {
								x = b;
								for (; x <= old; x++) {
									/** @type {number} */
									index = (x - cx) * (x - cx) + (y - cy) * (y - cy);
									if (!(index > w * w)) {
										index = y * length + x;
										/** @type {number} */
										key = obj[index];
										if (0 <= key && args[key] != message) {
											items[key].x += 10 * (x - cx);
											items[key].y += 10 * (y - cy);
										}
										if (0 == (y & 3) + (x & 3)) {
											/** @type {number} */
											index = (y >> 2) * step + (x >> 2);
											if (0 >= out[index]) {
												if (1 <= abs(x - cx)) {
													values[index].x += 10 / (x - cx);
												}
												if (1 <= abs(y - cy)) {
													values[index].y += 10 / (y - cy);
												}
											}
										}
									}
								}
							}
							/** @type {number} */
							args[i] = options;
						} else {
							if (args[i] == id) {
								values[x].add(items[i]);
								if (obj[index] == element) {
									/** @type {number} */
									obj[index] = temp;
								}
							} else {
								if (args[i] == current) {
									if (1 < expect(item) && 50 > apply(100)) {
										/** @type {number} */
										args[i] = 11;
									}
									cb(item, 0, 0);
									index = done(i, item);
									index = index + (Number(9) - 4);
									index = index + (Number(9) - 4) * length;
									/** @type {number} */
									key = obj[index];
									if (0 <= key && 3 == hash[args[key]]) {
										/** @type {number} */
										args[i] = name;
									}
								} else {
									if (11 == args[i]) {
										item.y += clamp(0.01, 0.08);
										item.add(items[i]);
										parse(items[i], 0.7);
										index = done(i, item);
										index = index + (Number(3) - 1);
										index = index + (Number(3) - 1) * length;
										/** @type {number} */
										key = obj[index];
										if (0 <= key && 6 != args[key] && 9 != args[key] && 11 != args[key] && args[key] != string && args[key] != p && args[key] != h) {
											/** @type {number} */
											args[i] = args[key] == current ? current : name;
										}
									} else {
										if (args[i] == n) {
											if (item.add(items[i]), parse(items[i], 0.7), done(i, item), 10 > apply(100)) {
												return call(i), 1;
											}
										} else {
											if (args[i] == line) {
												parse(item, 0.05);
												items[i].add(item);
												items[i].y += 0.01;
												parse(items[i], 0.999);
												item.set(items[i]);
												parse(item, 3.8 / (expect(item) + 1));
												/** @type {number} */
												j = ~~params[i].y * length + ~~(params[i].x + item.x);
												if (obj[j] <= temp) {
													params[i].x += item.x;
												} else {
													if (-1 >= obj[j]) {
														items[i].x *= -0.9;
														items[i].y *= 0.9;
													} else {
														if (0 <= obj[j]) {
															if (2 == hash[args[obj[j]]] && args[obj[j]] != undefined) {
																items[obj[j]].x -= items[i].x;
																items[i].x *= 0.5;
																x = params[i].x;
																params[i].x = params[obj[j]].x;
																params[obj[j]].x = x;
																/** @type {number} */
																result[obj[j]] = index;
																/** @type {number} */
																obj[index] = obj[j];
															} else {
																if (args[obj[j]] == options) {
																	x = params[i].x;
																	params[i].x = params[obj[j]].x;
																	params[obj[j]].x = x;
																	/** @type {number} */
																	result[obj[j]] = index;
																	/** @type {number} */
																	obj[index] = obj[j];
																} else {
																	if (args[obj[j]] == line) {
																		/** @type {number} */
																		x = 0.9 * items[i].x;
																		/** @type {number} */
																		items[i].x = 0.9 * items[obj[j]].x;
																		/** @type {number} */
																		items[obj[j]].x = x;
																	} else {
																		items[i].x *= -langreverse[args[obj[j]]];
																		items[i].y *= illuminant[args[obj[j]]];
																	}
																}
															}
														}
													}
												}
												/** @type {number} */
												index = ~~params[i].y * length + ~~params[i].x;
												/** @type {number} */
												obj[index] = element;
												/** @type {number} */
												j = ~~(params[i].y + item.y) * length + ~~params[i].x;
												if (obj[j] <= temp) {
													params[i].y += item.y;
												} else {
													if (-1 >= obj[j]) {
														items[i].y *= -0.9;
														items[i].x *= 0.9;
													} else {
														if (0 <= obj[j]) {
															if (2 == hash[args[obj[j]]] && args[obj[j]] != undefined) {
																items[obj[j]].y -= items[i].y;
																items[i].y *= 0.5;
																y = params[i].y;
																params[i].y = params[obj[j]].y;
																params[obj[j]].y = y;
																/** @type {number} */
																result[obj[j]] = index;
																/** @type {number} */
																obj[index] = obj[j];
															} else {
																if (args[obj[j]] == options) {
																	y = params[i].y;
																	params[i].y = params[obj[j]].y;
																	params[obj[j]].y = y;
																	/** @type {number} */
																	result[obj[j]] = index;
																	/** @type {number} */
																	obj[index] = obj[j];
																} else {
																	if (args[obj[j]] == line) {
																		if (0 < items[i].y) {
																			/** @type {number} */
																			x = 0.45 * items[i].y;
																			items[i].y *= -0.45;
																			items[i].y += items[obj[j]].y;
																			/** @type {number} */
																			items[obj[j]].y = x;
																		} else {
																			/** @type {number} */
																			x = 0.45 * items[obj[j]].y;
																			items[obj[j]].y *= -0.45;
																			items[obj[j]].y += items[i].y;
																			/** @type {number} */
																			items[i].y = x;
																		}
																	} else {
																		items[i].y *= -langreverse[args[obj[j]]];
																		items[i].x *= illuminant[args[obj[j]]];
																	}
																}
															}
														}
													}
												}
												/** @type {number} */
												result[i] = ~~params[i].y * length + ~~params[i].x;
												/** @type {number} */
												obj[result[i]] = i;
											} else {
												if (args[i] == string) {
													if (cb(item, 0, 0), index = done(i, item), 0 == arr[i]) {
														index = index + (Number(5) - 1);
														index = index + (Number(5) - 1) * length;
														/** @type {number} */
														key = obj[index];
														if (0 <= key) {
															/** @type {number} */
															arr[i] = args[key] == string ? arr[key] : args[key];
														}
													} else {
														if (1E3 > beginHint[max] - k) {
															return 0;
														}
														/** @type {number} */
														x = ~~params[i].x + Number(3) - 1;
														/** @type {number} */
														y = ~~params[i].y + Number(3) - 1;
														/** @type {number} */
														index = y * length + x;
														if (obj[index] <= temp && 10 > apply(100)) {
															callback(x, y, arr[i]);
														}
													}
												} else {
													if (args[i] == all) {
														if (items[i].x += 0.1 * values[x].x, items[i].y += 0.1 * values[x].y, item.y += clamp(0.1, 0.2), parse(items[i], 0.9), item.add(items[i]), index = done(i, item), 0 == arr[i]) {
															arr[i] = 0 != theCache[url] ? theCache[url] : 0 != theCache[l] ? theCache[l] : _;
														} else {
															if (100 > arr[i]) {
																index = index + (Number(3) - 1);
																index = index + (Number(3) - 1) * length;
																if (0 <= obj[index] && 3 == hash[args[obj[index]]]) {
																	items[i].y -= 0.1;
																	get(items[i]);
																	parse(items[i], 50);
																	arr[i] += 100;
																}
															} else {
																if (5E3 > arr[i]) {
																	return arr[i] += 100, 0;
																}
																if (5 < apply(100)) {
																	return 0;
																}
																if (1E3 > beginHint[max] - k) {
																	return call(i), 1;
																}
																/** @type {number} */
																w = 0;
																for (; 512 > w; w = w + 32) {
																	/** @type {number} */
																	x = ~~(params[i].x + 2 * grid[w][0]);
																	/** @type {number} */
																	y = ~~(params[i].y + 2 * grid[w][1]);
																	x = clamp(x, 8, 408);
																	y = clamp(y, 8, 308);
																	index = y * length + x;
																	if (obj[index] <= temp) {
																		index = callback(x, y, arr[i] % 100);
																		if (0 <= index) {
																			items[index].x += 20 * grid[w][0];
																			items[index].y += 20 * grid[w][1];
																		}
																	}
																}
																call(i);
																return 1;
															}
														}
													} else {
														if (args[i] == r) {
															items[i].x += 0.2 * values[x].x;
															items[i].y += 0.2 * values[x].y;
															if (obj[index + length] != element) {
																if (obj[index - 1] == element) {
																	items[i].x -= clamp(0.1, 0.2);
																}
																if (obj[index + 1] == element) {
																	items[i].x += clamp(0.1, 0.2);
																}
															}
															items[i].x += clamp(-0.01, 0.01);
															items[i].y += clamp(0.01, 0.05);
															parse(items[i], 0.9);
															item.add(items[i]);
															index = done(i, item);
															x = Number(8);
															j = 5 > x ? index - length : 6 > x ? index - 1 : 7 > x ? index + 1 : index + length;
															/** @type {number} */
															key = obj[j];
															if (0 <= key) {
																if (7 > x && (1 == hash[args[key]] && args[key] != tag || args[key] == name || args[key] == code || 37 == args[key])) {
																	if (10 > apply(100)) {
																		iterator(i, key, index, j);
																	}
																} else {
																	if (3 == hash[args[key]]) {
																		/** @type {number} */
																		arr[i] = 1;
																	} else {
																		if (args[key] == action && 256 > arr[key]) {
																			return arr[key] = r, call(i), 1;
																		}
																		if (args[key] == none && 0 == map[key]) {
																			return arr[key] = 4 | (5 > x ? 2 : 6 > x ? 1 : 7 > x ? 3 : 0), map[key] = r, call(i), 1;
																		}
																	}
																}
															}
															if (1 == arr[i] && (x = ~~params[i].x + Number(3) - 1, y = ~~params[i].y + Number(3) - 1, j = y * length + x, obj[j] <= temp && callback(x, y, options), 10 > apply(100))) {
																return call(i), 1;
															}
														} else {
															if (args[i] == command) {
																if (cb(item, 0, 0), index = done(i, item), 0 == arr[i]) {
																	index = index + (Number(3) - 1);
																	index = index + (Number(3) - 1) * length;
																	/** @type {number} */
																	key = obj[index];
																	if (0 <= key && 3 == hash[args[key]]) {
																		/** @type {number} */
																		arr[i] = 1;
																	}
																} else {
																	/** @type {number} */
																	w = 0;
																	for (; 8 > w; w++) {
																		j = index + topDomains[w];
																		/** @type {number} */
																		key = obj[j];
																		if (0 <= key && args[key] == command) {
																			/** @type {number} */
																			arr[key] = 1;
																		}
																	}
																	/** @type {number} */
																	w = 10;
																	/** @type {number} */
																	cx = params[i].x & 65524;
																	/** @type {number} */
																	cy = params[i].y & 65524;
																	b = max(cx - w, width);
																	x = max(cy - w, width);
																	old = min(cx + w, length - width - 1);
																	oldProto = min(cy + w, (cols - 1) * width - 1);
																	y = x;
																	for (; y <= oldProto; y++) {
																		x = b;
																		for (; x <= old; x++) {
																			/** @type {number} */
																			index = (x - cx) * (x - cx) + (y - cy) * (y - cy);
																			if (!(index > w * w)) {
																				j = y * length + x;
																				/** @type {number} */
																				key = obj[j];
																				if (0 <= key) {
																					items[key].x += 10 * (x - cx);
																					items[key].y += 10 * (y - cy);
																				}
																				if (0 == (y & 3) + (x & 3)) {
																					/** @type {number} */
																					j = (y >> 2) * step + (x >> 2);
																					if (0 >= out[j]) {
																						if (1 <= abs(x - cx)) {
																							values[j].x += 1 / (x - cx);
																						}
																						if (1 <= abs(y - cy)) {
																							values[j].y += 1 / (y - cy);
																						}
																					}
																				}
																			}
																		}
																	}
																	call(i);
																	return 1;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
};
/** @type {function(number, !Object): ?} */
msg.fff = e.prototype.D;
/**
 * @param {number} name
 * @param {!Object} data
 * @return {?}
 */
e.prototype.D = function(name, data) {
	var x;
	var n;
	var index;
	var j;
	/** @type {number} */
	n = (params[name].y >> 2) * step + (params[name].x >> 2);
	/** @type {number} */
	index = result[name];
	/** @type {number} */
	obj[index] = element;
	data.set(values[n]);
	if (args[name] == tag) {
		items[name].x += 0.05 * values[n].x;
		items[name].y += 0.05 * values[n].y;
		items[name].y += clamp(0.01, 0.05);
		parse(items[name], 0.95);
		data.set(items[name]);
		if (10 < expect(data) && 50 > apply(100)) {
			/** @type {number} */
			args[name] = _;
		}
		parse(data, 3.8 / (expect(data) + 1));
		/** @type {number} */
		j = ~~params[name].y * length + ~~(params[name].x + data.x);
		if (obj[j] <= temp) {
			params[name].x += data.x;
		} else {
			if (0 <= obj[j]) {
				if (2 == hash[args[obj[j]]] && args[obj[j]] != undefined || args[obj[j]] == object) {
					items[obj[j]].x -= items[name].x;
					var d = params[name].x;
					params[name].x = params[obj[j]].x;
					params[obj[j]].x = d;
					/** @type {number} */
					result[obj[j]] = index;
					/** @type {number} */
					obj[index] = obj[j];
				} else {
					if (args[obj[j]] == _ || args[obj[j]] == number || args[obj[j]] == message || args[obj[j]] == all || args[obj[j]] == group) {
						items[obj[j]].x += apply(items[name].x);
					}
				}
			}
			items[name].x *= 0.5;
		}
		/** @type {number} */
		index = ~~params[name].y * length + ~~params[name].x;
		/** @type {number} */
		obj[index] = element;
		/** @type {number} */
		j = ~~(params[name].y + data.y) * length + ~~params[name].x;
		if (obj[j] <= temp) {
			params[name].y += data.y;
		} else {
			if (0 <= obj[j]) {
				if (2 == hash[args[obj[j]]] && args[obj[j]] != undefined || args[obj[j]] == object) {
					items[obj[j]].y -= items[name].y;
					var s = params[name].y;
					params[name].y = params[obj[j]].y;
					params[obj[j]].y = s;
					/** @type {number} */
					result[obj[j]] = index;
					/** @type {number} */
					obj[index] = obj[j];
				} else {
					if (args[obj[j]] == _ || args[obj[j]] == number || args[obj[j]] == message || args[obj[j]] == all || args[obj[j]] == group) {
						items[obj[j]].y += apply(items[name].y);
					}
				}
			}
			items[name].y *= 0.5;
		}
		/** @type {number} */
		result[name] = ~~params[name].y * length + ~~params[name].x;
		/** @type {number} */
		obj[result[name]] = name;
	} else {
		if (args[name] == object) {
			items[name].x += 0.1 * values[n].x;
			items[name].y += 0.1 * values[n].y;
			if (obj[index + length] != element) {
				if (obj[index - 1] == element) {
					items[name].x -= clamp(0, 0.1);
				}
				if (obj[index + 1] == element) {
					items[name].x += clamp(0, 0.1);
				}
			}
			items[name].x += clamp(-0.01, 0.01);
			items[name].y += clamp(0.01, 0.1);
			parse(items[name], 0.9);
			data.add(items[name]);
			index = done(name, data);
			index = index + (Number(5) - 2);
			index = index + (Number(5) - 2) * length;
			/** @type {number} */
			var i = obj[index - length];
			if (0 <= i) {
				if (args[i] == _) {
					/** @type {number} */
					args[i] = options;
				} else {
					if (args[i] == name || args[i] == v) {
						if (args[name] = tag, args[i] = n, 50 > apply(100)) {
							return call(name), 1;
						}
					} else {
						if (args[i] == number) {
							/** @type {number} */
							args[i] = options;
						} else {
							if (args[i] == line) {
								/** @type {number} */
								args[i] = options;
							} else {
								if (args[i] == tag) {
									items[i].x += clamp(-0.1, 0.1);
									if (5 > apply(100)) {
										/** @type {number} */
										args[i] = object;
									}
								} else {
									if (args[i] == group) {
										/** @type {number} */
										args[i] = options;
									} else {
										if (args[i] == p) {
											/** @type {number} */
											args[i] = options;
										} else {
											if (37 == args[i]) {
												if (args[name] = tag, args[i] = size, 50 > apply(100)) {
													return call(name), 1;
												}
											} else {
												if (args[i] == key) {
													if (50 > apply(100)) {
														/** @type {number} */
														args[i] = object;
													}
												} else {
													if (args[i] == undefined && 1 > apply(100)) {
														/** @type {number} */
														args[i] = object;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			d = Number(4);
			j = 1 > d ? index - length : 2 > d ? index - 1 : 3 > d ? index + 1 : index + length;
			/** @type {number} */
			i = obj[j];
			if (0 <= i && args[i] == none && 0 == map[i]) {
				return arr[i] = 4 | (1 > d ? 2 : 2 > d ? 1 : 3 > d ? 3 : 0), map[i] = object, call(name), 1;
			}
		} else {
			if (args[name] == delimiter) {
				data.y += clamp(0, 0.1);
				data.add(items[name]);
				parse(items[name], 0.7);
				index = done(name, data);
				if (0 == arr[name]) {
					j = index + (Number(3) - 1);
					j = j + (Number(3) - 1) * length;
					if (0 <= obj[j] && args[obj[j]] != delimiter) {
						/** @type {number} */
						arr[name] = args[obj[j]];
					}
				} else {
					if (2048 >= arr[name]) {
						j = index + (Number(3) - 1);
						j = j + (Number(3) - 1) * length;
						if (index != j && 0 <= obj[j] && (args[obj[j]] != delimiter || 0 == arr[obj[j]])) {
							/** @type {number} */
							args[obj[j]] = delimiter;
							/** @type {number} */
							arr[obj[j]] = arr[name] & 255;
							/** @type {number} */
							map[obj[j]] = 0;
						}
						arr[name] += 256;
					} else {
						arr[name] += 256;
						if (32768 <= arr[name]) {
							/** @type {number} */
							args[name] = arr[name] & 255;
							/** @type {number} */
							arr[name] = 0;
							cb(items[name], 0, 0);
						}
					}
				}
			} else {
				if (args[name] == code) {
					items[name].x += 0.2 * values[n].x;
					items[name].y += 0.2 * values[n].y;
					if (obj[index + length] != element) {
						if (obj[index - 1] == element) {
							items[name].x -= clamp(0.1, 0.2);
						}
						if (obj[index + 1] == element) {
							items[name].x += clamp(0.1, 0.2);
						}
					}
					items[name].x += clamp(-0.01, 0.01);
					items[name].y += clamp(0.01, 0.05);
					parse(items[name], 0.9);
					data.add(items[name]);
					index = done(name, data);
					d = Number(8);
					j = 5 > d ? index - length : 6 > d ? index - 1 : 7 > d ? index + 1 : index + length;
					/** @type {number} */
					i = obj[j];
					if (0 <= i) {
						if (7 > d && 1 == hash[args[i]] && args[i] != tag) {
							if (10 > apply(100)) {
								iterator(name, i, index, j);
							}
						} else {
							if (args[i] == action && 256 > arr[i]) {
								return arr[i] = code, call(name), 1;
							}
							if (args[i] == none && 0 == map[i]) {
								return arr[i] = 4 | (5 > d ? 2 : 6 > d ? 1 : 7 > d ? 3 : 0), map[i] = code, call(name), 1;
							}
						}
					}
					if (10 > expect(items[name]) && (j = index + (Number(5) - 2), j = j + (Number(5) - 2) * length, 0 > obj[j] || 3 != hash[args[obj[j]]])) {
						return 0;
					}
					/** @type {number} */
					index = 10;
					/** @type {number} */
					x = params[name].x & 65532;
					/** @type {number} */
					var e = params[name].y & 65532;
					var b = max(x - index, width);
					i = max(e - index, width);
					var old = min(x + index, length - width - 1);
					var oldProto = min(e + index, (cols - 1) * width - 1);
					s = i;
					for (; s <= oldProto; s++) {
						d = b;
						for (; d <= old; d++) {
							/** @type {number} */
							j = (d - x) * (d - x) + (s - e) * (s - e);
							if (!(j > index * index)) {
								j = s * length + d;
								if (0 <= obj[j]) {
									items[obj[j]].x += 10 * (d - params[name].x);
									items[obj[j]].y += 10 * (s - params[name].y);
								}
								if (0 == (s & 3) + (d & 3)) {
									/** @type {number} */
									j = (s >> 2) * step + (d >> 2);
									if (0 >= out[j]) {
										if (1 <= abs(d - x)) {
											values[j].x += 10 / (d - x);
										}
										if (1 <= abs(s - e)) {
											values[j].y += 10 / (s - e);
										}
									}
								}
							}
						}
					}
					/** @type {number} */
					args[name] = options;
				} else {
					if (args[name] == group) {
						/** @type {number} */
						i = obj[index + length];
						if (0 == arr[name] && 0 <= i && (6 == args[i] || args[i] == current || args[i] == command || args[i] == val || args[i] == p || args[i] == key || args[i] == action || args[i] == none)) {
							/** @type {number} */
							arr[name] = args[i] << 2;
						}
						if (0 == arr[name]) {
							data.y += clamp(0.01, 0.2);
							if (i != element) {
								if (obj[index - 1] == element) {
									items[name].x -= clamp(0, 0.1);
								}
								if (obj[index + 1] == element) {
									items[name].x += clamp(0, 0.1);
								}
							}
						} else {
							cb(data, 0, 0);
						}
						data.add(items[name]);
						parse(items[name], 0.85);
						index = done(name, data);
						if (0 == arr[name] || 1E3 > beginHint[max] - k) {
							return 0;
						}
						/** @type {number} */
						d = arr[name] & 3;
						j = index + [1, length, -1, -length][d];
						/** @type {number} */
						i = obj[j];
						if (i <= temp) {
							/** @type {number} */
							arr[name] = arr[name] & 16777212 | d + 1 & 3;
							j = callback(j % length, ~~(j / length), group);
							if (0 < j) {
								/** @type {number} */
								arr[j] = arr[name];
							}
							/** @type {number} */
							args[name] = arr[name] >> 2;
							/** @type {number} */
							arr[name] = 0;
						} else {
							if (0 <= i) {
								return args[i] == arr[name] >> 2 && (arr[name] = arr[name] & 16777212 | d - 1 & 3), args[i] = args[name], arr[i] = arr[name], map[i] = 0, call(name), 1;
							}
							/** @type {number} */
							arr[name] = arr[name] & 16777212 | d + 1 & 3;
						}
					} else {
						if (args[name] == elem) {
							if (cb(data, 0, 0), index = done(name, data), index = index + (Number(5) - 2), index = index + (Number(5) - 2) * length, i = obj[index], 0 <= i) {
								if (args[i] == _) {
									/** @type {number} */
									args[i] = options;
								} else {
									if (args[i] == name || args[i] == v || 37 == args[i]) {
										return call(name), 1;
									}
									if (args[i] == number) {
										/** @type {number} */
										args[i] = options;
									} else {
										if (6 == args[i]) {
											/** @type {number} */
											args[i] = elem;
										} else {
											if (11 == args[i]) {
												/** @type {number} */
												args[i] = name;
											} else {
												if (args[i] == line) {
													/** @type {number} */
													args[i] = options;
												} else {
													if (args[i] == group) {
														/** @type {number} */
														args[i] = options;
													} else {
														if (args[i] == p) {
															/** @type {number} */
															args[i] = options;
														}
													}
												}
											}
										}
									}
								}
							}
						} else {
							if (args[name] == date) {
								data.y += clamp(0, -0.02);
								data.add(items[name]);
								parse(items[name], 0.9);
								index = done(name, data);
								d = Number(4);
								j = 1 > d ? index - length : 2 > d ? index - 1 : 3 > d ? index + 1 : index + length;
								/** @type {number} */
								i = obj[j];
								if (0 <= i) {
									if (3 > d && (1 == hash[args[i]] || 2 == hash[args[i]])) {
										iterator(name, i, index, j);
									} else {
										if (args[i] == date) {
											items[name].x += clamp(-0.2, 0.2);
											items[name].y += clamp(-0.2, 0.2);
										} else {
											if (args[i] == none && 0 == map[i]) {
												return arr[i] = 4 | (1 > d ? 2 : 2 > d ? 1 : 3 > d ? 3 : 0), map[i] = date, call(name), 1;
											}
										}
									}
								}
								if (0 == arr[name]) {
									if (j = index + (Number(5) - 2), j = j + (Number(5) - 2) * length, 0 > obj[j] || 3 != hash[args[obj[j]]]) {
										return 0;
									}
								} else {
									if (2 > arr[name]) {
										return arr[name]++, 0;
									}
								}
								/** @type {number} */
								index = 10;
								/** @type {number} */
								x = ~~params[name].x;
								/** @type {number} */
								e = ~~params[name].y;
								b = max(x - index, width);
								i = max(e - index, width);
								old = min(x + index, length - width - 1);
								oldProto = min(e + index, (cols - 1) * width - 1);
								s = i;
								for (; s <= oldProto; s++) {
									d = b;
									for (; d <= old; d++) {
										/** @type {number} */
										j = (d - x) * (d - x) + (s - e) * (s - e);
										if (!(j > index * index)) {
											j = s * length + d;
											/** @type {number} */
											i = obj[j];
											if (0 <= i && args[i] == date) {
												/** @type {number} */
												arr[i] = 1;
											}
											if (i <= temp && 1 > apply(100)) {
												callback(d, s, options);
											}
										}
									}
								}
								buf[n] += 2;
								/** @type {number} */
								t = t - 2;
								/** @type {number} */
								args[name] = options;
								/** @type {number} */
								arr[name] = 0;
							} else {
								if (args[name] == v) {
									if (1 == arr[name]) {
										return call(name), 1;
									}
									items[name].x += 0.3 * values[n].x;
									items[name].y += 0.3 * values[n].y;
									if (obj[index + length] != element) {
										if (obj[index - 1] == element) {
											items[name].x -= clamp(0.1, 0.2);
										}
										if (obj[index + 1] == element) {
											items[name].x += clamp(0.1, 0.2);
										}
									}
									items[name].x += clamp(-0.01, 0.01);
									items[name].y += clamp(0.01, 0.05);
									parse(items[name], 0.9);
									data.add(items[name]);
									index = done(name, data);
									d = Number(8);
									j = 5 > d ? index - length : 6 > d ? index - 1 : 7 > d ? index + 1 : index + length;
									/** @type {number} */
									i = obj[j];
									if (0 <= i) {
										if (7 > d && (1 == hash[args[i]] && args[i] != tag || args[i] == code || 37 == args[i])) {
											if (10 > apply(100)) {
												iterator(name, i, index, j);
											}
										} else {
											if (args[i] == current) {
												if (50 > apply(100)) {
													/** @type {number} */
													args[name] = current;
												}
											} else {
												if (args[i] == r) {
													/** @type {number} */
													args[i] = v;
													/** @type {number} */
													arr[i] = 1;
													/** @type {number} */
													arr[name] = 1;
												} else {
													if (args[i] == action && 256 > arr[i]) {
														return arr[i] = v, call(name), 1;
													}
													if (args[i] == none && 0 == map[i]) {
														return arr[i] = 4 | (5 > d ? 2 : 6 > d ? 1 : 7 > d ? 3 : 0), map[i] = v, call(name), 1;
													}
												}
											}
										}
									}
									if (2 < expect(items[name])) {
										/** @type {number} */
										j = 0;
										/** @type {number} */
										index = 4;
										/** @type {number} */
										x = ~~params[name].x;
										/** @type {number} */
										e = ~~params[name].y;
										b = max(x - index, width);
										i = max(e - index, width);
										old = min(x + index, length - width - 1);
										oldProto = min(e + index, (cols - 1) * width - 1);
										s = i;
										for (; s <= oldProto; s++) {
											d = b;
											for (; d <= old; d++) {
												if (!(index * index < (d - x) * (d - x) + (s - e) * (s - e))) {
													/** @type {number} */
													i = obj[s * length + d];
													if (0 <= i && args[i] == v && 0 == arr[i]) {
														/** @type {number} */
														arr[i] = 1;
														j++;
													}
												}
											}
										}
										j = min(max(5, j), model - m);
										if (5 > j) {
											return 0;
										}
										/** @type {number} */
										d = (parseInt(clamp(params[name].x, 8, 407)) >> 2 << 2) + 2;
										/** @type {number} */
										s = (parseInt(clamp(params[name].y, 8, 307)) >> 2 << 2) + 2;
										content++;
										/** @type {number} */
										x = 0;
										for (; x < j; x++) {
											pick(d + 1.9 * grid[~~(512 * x / j)][0], s + 1.9 * grid[~~(512 * x / j)][1]);
										}
										content++;
										call(name);
										return 1;
									}
								} else {
									if (args[name] == end) {
										if (obj[index] = name, cb(items[name], 0, 0), 4096 > arr[name]) {
											if (0 == arr[name] && (arr[name] = n % 1E3), n = arr[name] >> 10, i = arr[name] & 1023, i = 73 * i % 955 + 44, 0 == n ? (j = i % 3, 0 == j ? (d = -1, s = 0, n = 1) : 1 == j ? (d = 1, s = 0, n = 3) : (d = 0, s = 1, n = 
																																																																													  0)) : 1 == n ? 0 >= i % 2 ? (d = -1, s = 0, n = 1) : (d = 0, s = 1, n = 0) : 0 >= i % 2 ? (d = 1, s = 0, n = 3) : (d = 0, s = 1, n = 0), j = ~~(params[name].y + s) * length + ~~(params[name].x + d), x = n << 10 | i, 
												 i = obj[j], i <= temp) {
												/** @type {number} */
												obj[index] = element;
												params[name].x += d;
												params[name].y += s;
												/** @type {number} */
												obj[j] = name;
												/** @type {number} */
												arr[name] = x;
												/** @type {number} */
												result[name] = j;
											} else {
												if (0 <= i) {
													if (args[i] != end || arr[i] != x) {
														if (args[i] == end) {
															return call(name), 1;
														}
														if (args[i] == val || args[i] == undefined) {
															return args[i] == val ? arr[i] = 6E3 + n : args[i] == undefined && (arr[i] = 6100 + n), args[i] = end, call(name), 1;
														}
														if (1 == hash[args[i]] || 2 == hash[args[i]] || args[i] == object || 6 == args[i] || args[i] == current || args[i] == p || args[i] == key) {
															/** @type {number} */
															arr[name] = 5E3;
														} else {
															if (args[i] == h) {
																iterator(name, i, index, j);
															} else {
																return call(name), 1;
															}
														}
													}
												} else {
													if (temp < i) {
														return call(name), 1;
													}
												}
											}
										} else {
											if (5E3 == arr[name]) {
												/** @type {number} */
												index = 6;
												/** @type {number} */
												x = ~~params[name].x;
												/** @type {number} */
												e = ~~params[name].y;
												b = max(x - index, width);
												i = max(e - index, width);
												old = min(x + index, length - width - 1);
												oldProto = min(e + index, (cols - 1) * width - 1);
												s = i;
												for (; s <= oldProto; s++) {
													d = b;
													for (; d <= old; d++) {
														/** @type {number} */
														j = (d - x) * (d - x) + (s - e) * (s - e);
														if (!(j > index * index)) {
															j = s * length + d;
															/** @type {number} */
															i = obj[j];
															if (0 <= i && args[i] != end) {
																if (args[i] == current) {
																	/** @type {number} */
																	args[i] = 11;
																} else {
																	if (args[i] == all && 0 < arr[i] && 5E3 > arr[i]) {
																		arr[i] += 100;
																	}
																}
																items[i].x -= 3 * (d - params[name].x);
																items[i].y -= 3 * (s - params[name].y);
															}
														}
													}
												}
												call(name);
												return 1;
											}
											if (7E3 <= arr[name]) {
												if (7E3 == arr[name]) {
													/** @type {!Array} */
													d = [length, -1, -length, 1];
													/** @type {number} */
													x = 0;
													for (; 4 > x; x++) {
														/** @type {number} */
														i = obj[index + d[x]];
														if (0 <= i && args[i] == key) {
															/** @type {number} */
															args[i] = end;
															/** @type {number} */
															arr[i] = 7E3;
														}
													}
												}
												arr[name]++;
												if (7020 < arr[name]) {
													/** @type {number} */
													args[name] = key;
													/** @type {number} */
													arr[name] = 0;
												}
											} else {
												if (6E3 <= arr[name]) {
													/** @type {number} */
													n = arr[name] & 3;
													/** @type {number} */
													e = 6E3 == (arr[name] & 65532) ? val : undefined;
													/** @type {!Array} */
													d = [length, -1, -length, 1];
													/** @type {number} */
													x = 0;
													for (; 4 > x; x++) {
														if (2 != x && (j = index + d[n + x & 3], i = obj[j], 0 <= i)) {
															if (args[i] == val || args[i] == undefined) {
																iterator(name, i, index, j);
																if (args[i] == val) {
																	/** @type {number} */
																	arr[name] = 6E3 + (n + x & 3);
																} else {
																	if (args[i] == undefined) {
																		/** @type {number} */
																		arr[name] = 6100 + (n + x & 3);
																	}
																}
																/** @type {number} */
																args[i] = e;
																/** @type {number} */
																arr[i] = 0;
																break;
															} else {
																if (args[i] == end && 6E3 <= arr[i] && 7E3 > arr[i]) {
																	/** @type {number} */
																	args[name] = e;
																	/** @type {number} */
																	arr[name] = 0;
																	break;
																} else {
																	if (args[i] == key) {
																		/** @type {number} */
																		args[i] = end;
																		/** @type {number} */
																		arr[i] = 7E3;
																	}
																}
															}
														}
													}
													if (4 == x) {
														if (obj[index + d[n]] <= temp) {
															/** @type {number} */
															d = ~~params[name].x;
															/** @type {number} */
															s = ~~params[name].y;
															if (0 == n) {
																callback(d, s + 1, end);
															} else {
																if (1 == n) {
																	callback(d - 1, s, end);
																} else {
																	if (2 == n) {
																		callback(d, s - 1, end);
																	} else {
																		if (3 == n) {
																			callback(d + 1, s, end);
																		}
																	}
																}
															}
														}
														/** @type {number} */
														args[name] = e;
														/** @type {number} */
														arr[name] = 0;
													}
												}
											}
										}
									} else {
										if (args[name] == val) {
											/** @type {number} */
											obj[index] = name;
											cb(items[name], 0, 0);
											/** @type {number} */
											index = index + (Number(5) - 2);
											/** @type {number} */
											index = index + (Number(5) - 2) * length;
											/** @type {number} */
											i = obj[index];
											if (0 <= i) {
												if (args[i] == name) {
													if (2 > apply(100)) {
														/** @type {number} */
														args[name] = _;
													}
												} else {
													if (args[i] == object && 2 > apply(100)) {
														/** @type {number} */
														args[name] = object;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
};
/** @type {function(number, !Object): ?} */
msg.fff = e.prototype.F;
/**
 * @param {number} i
 * @param {!Object} a
 * @return {?}
 */
e.prototype.F = function(i, a) {
	var b;
	var j;
	var index;
	var x;
	/** @type {number} */
	j = (params[i].y >> 2) * step + (params[i].x >> 2);
	/** @type {number} */
	index = result[i];
	/** @type {number} */
	obj[index] = element;
	a.set(values[j]);
	if (args[i] == host) {
		items[i].y += 0.03;
		parse(items[i], 0.92);
		a.add(items[i]);
		index = done(i, a);
		if (0 != arr[i]) {
			if (arr[i] == host) {
				return call(i), 1;
			}
			if (5 < apply(100)) {
				return 0;
			}
			if (arr[i] == current) {
				/** @type {number} */
				args[i] = 11;
				/** @type {number} */
				arr[i] = 0;
			} else {
				if (6 == arr[i] || arr[i] == tag || arr[i] == p) {
					/** @type {number} */
					args[i] = _;
					/** @type {number} */
					arr[i] = 0;
				} else {
					if (arr[i] == code || arr[i] == elem) {
						/** @type {number} */
						args[i] = options;
						/** @type {number} */
						arr[i] = 1;
					} else {
						if (arr[i] == v) {
							/** @type {number} */
							args[i] = n;
							/** @type {number} */
							arr[i] = 0;
						} else {
							if (arr[i] == val) {
								/** @type {number} */
								args[i] = val;
								/** @type {number} */
								arr[i] = 0;
							} else {
								if (arr[i] == key) {
									/** @type {number} */
									args[i] = tag;
									/** @type {number} */
									arr[i] = 0;
								} else {
									if (arr[i] == none) {
										/** @type {number} */
										args[i] = event;
										/** @type {number} */
										arr[i] = 0;
									} else {
										return call(i), 1;
									}
								}
							}
						}
					}
				}
			}
			return 0;
		}
		x = index + (Number(3) - 1);
		x = x + (Number(3) - 1) * length;
		/** @type {number} */
		j = obj[x];
		if (0 > j || args[j] == host || args[j] == string) {
			return 0;
		}
		/** @type {number} */
		index = 4;
		/** @type {number} */
		b = ~~params[i].x;
		/** @type {number} */
		var g = ~~params[i].y;
		var p = max(b - index, width);
		var result = max(g - index, width);
		var parent = min(b + index, length - width - 1);
		var target = min(g + index, (cols - 1) * width - 1);
		cb(a, 0, 0);
		var r = result;
		for (; r <= target; r++) {
			var c = p;
			for (; c <= parent; c++) {
				/** @type {number} */
				var value = (c - b) * (c - b) + (r - g) * (r - g);
				if (!(value > index * index)) {
					x = r * length + c;
					/** @type {number} */
					j = obj[x];
					if (0 <= j && args[j] != host) {
						a.x += params[i].x - c;
						a.y += params[i].y - r;
					}
				}
			}
		}
		get(a);
		r = result;
		for (; r <= target; r++) {
			c = p;
			for (; c <= parent; c++) {
				if (value = (c - b) * (c - b) + (r - g) * (r - g), !(value > index * index) && (x = r * length + c, j = obj[x], 0 <= j && args[j] != string && (items[j].x += a.x + 1 * (params[i].x - c), items[j].y += a.y + 
																																																				1 * (params[i].y - r), args[j] != host || 0 == arr[j]))) {
					/** @type {number} */
					map[j] = 0;
					/** @type {number} */
					arr[j] = args[j];
					/** @type {number} */
					args[j] = host;
				}
			}
		}
		call(i);
		return 1;
	}
	if (args[i] == title) {
		/** @type {number} */
		obj[index] = i;
		cb(items[i], 0, 0);
		/** @type {number} */
		value = arr[i] & 15;
		/** @type {number} */
		r = arr[i] >> 4 & 15;
		/** @type {number} */
		c = arr[i] >> 8 & 255;
		r++;
		if (1 == r) {
			return arr[i] = c << 8 | r << 4 | value, 0;
		}
		if (12 < r) {
			return c == key ? (args[i] = key, arr[i] = 0) : call(i), 1;
		}
		if (8 < r) {
			return arr[i] = c << 8 | r << 4 | value, 0;
		}
		if (0 == value) {
			if (target = obj[index + tags[0]], 0 <= target && args[target] == title && (target = -1), j = obj[index + tags[1]], 0 <= j && args[j] == title && (j = -1), x = obj[index + tags[2]], 0 <= x && args[x] == title && (x = -1), b = obj[index + tags[3]], 
				 0 <= b && args[b] == title && (b = -1), g = obj[index + tags[4]], 0 <= g && args[g] == title && (g = -1), p = obj[index + tags[5]], 0 <= p && args[p] == title && (p = -1), result = obj[index + tags[6]], 0 <= result && args[result] == title && 
				 (result = -1), parent = obj[index + tags[7]], 0 <= parent && args[parent] == title && (parent = -1), 0 <= b && 0 <= g && 0 <= p) {
				/** @type {number} */
				value = 1;
			} else {
				if (0 <= p && 0 <= result && 0 <= parent) {
					/** @type {number} */
					value = 3;
				} else {
					if (0 <= parent && 0 <= target && 0 <= j) {
						/** @type {number} */
						value = 5;
					} else {
						if (0 <= j && 0 <= x && 0 <= b) {
							/** @type {number} */
							value = 7;
						} else {
							if (0 <= p) {
								/** @type {number} */
								value = 2;
							} else {
								if (0 <= parent) {
									/** @type {number} */
									value = 4;
								} else {
									if (0 <= j) {
										/** @type {number} */
										value = 6;
									} else {
										if (0 <= b) {
											/** @type {number} */
											value = 8;
										} else {
											return arr[i] = 160 | value, 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		/** @type {number} */
		value = value - 1;
		/** @type {number} */
		j = obj[index + tags[value]];
		if (0 <= j) {
			if (args[j] == title) {
				/** @type {number} */
				b = 2;
				for (; 4 >= b; b++) {
					if (j = obj[index + tags[value] * b], 0 <= j) {
						if (args[j] != title) {
							break;
						}
					} else {
						if (j <= temp) {
							if (1E3 > beginHint[max] - k) {
								break;
							}
							x = callback(~~params[i].x + varWikidataTypes[value] * b, ~~params[i].y + priorityToColor[value] * b, title);
							if (0 < x) {
								/** @type {number} */
								arr[x] = value + 1;
							}
						}
						break;
					}
				}
			} else {
				if (args[j] == val || args[j] == undefined) {
					/** @type {number} */
					j = obj[index + tags[value + 1 & 7]];
					if (0 <= j && args[j] != val && args[j] != undefined) {
						/** @type {number} */
						j = -1;
					}
					/** @type {number} */
					x = obj[index + tags[value + 2 & 7]];
					if (0 <= x && args[x] != val && args[x] != undefined) {
						/** @type {number} */
						x = -1;
					}
					/** @type {number} */
					b = obj[index + tags[value + 3 & 7]];
					if (0 <= b && args[b] != val && args[b] != undefined) {
						/** @type {number} */
						b = -1;
					}
					/** @type {number} */
					g = obj[index + tags[value + 4 & 7]];
					if (0 <= g && args[g] != val && args[g] != undefined) {
						/** @type {number} */
						g = -1;
					}
					/** @type {number} */
					p = obj[index + tags[value + 5 & 7]];
					if (0 <= p && args[p] != val && args[p] != undefined) {
						/** @type {number} */
						p = -1;
					}
					/** @type {number} */
					result = obj[index + tags[value + 6 & 7]];
					if (0 <= result && args[result] != val && args[result] != undefined) {
						/** @type {number} */
						result = -1;
					}
					/** @type {number} */
					parent = obj[index + tags[value + 7 & 7]];
					if (0 <= parent && args[parent] != val && args[parent] != undefined) {
						/** @type {number} */
						parent = -1;
					}
					/** @type {number} */
					target = obj[index + tags[value] + tags[value + 1 & 7]];
					if (0 <= target && args[target] != val && args[target] != undefined) {
						/** @type {number} */
						target = -1;
					}
					/** @type {number} */
					var data = obj[index + tags[value] + tags[value + 2 & 7]];
					if (0 <= data && args[data] != val && args[data] != undefined) {
						/** @type {number} */
						data = -1;
					}
					/** @type {number} */
					var key = obj[index + tags[value] + tags[value + 3 & 7]];
					if (0 <= key && args[key] != val && args[key] != undefined) {
						/** @type {number} */
						key = -1;
					}
					/** @type {number} */
					var name = obj[index + tags[value] + tags[value + 5 & 7]];
					if (0 <= name && args[name] != val && args[name] != undefined) {
						/** @type {number} */
						name = -1;
					}
					/** @type {number} */
					var type = obj[index + tags[value] + tags[value + 6 & 7]];
					if (0 <= type && args[type] != val && args[type] != undefined) {
						/** @type {number} */
						type = -1;
					}
					/** @type {number} */
					var i = obj[index + tags[value] + tags[value + 7 & 7]];
					if (0 <= i && args[i] != val && args[i] != undefined) {
						/** @type {number} */
						i = -1;
					}
					if (0 == (value & 1)) {
						if (0 <= p && 0 <= result && 0 > j && 0 > x) {
							/** @type {number} */
							value = value + 1 & 7;
						} else {
							if (0 <= x && 0 <= b && 0 > parent && 0 > result) {
								/** @type {number} */
								value = value - 1 & 7;
							} else {
								if (0 <= j && 0 <= result && 0 > x && 0 > b && 0 > p) {
									/** @type {number} */
									value = value + 3 & 7;
								} else {
									if (0 <= target && 0 <= type && 0 > data && 0 > key && 0 > name) {
										/** @type {number} */
										value = value + 3 & 7;
									} else {
										if (0 <= x && 0 <= parent && 0 > b && 0 > p && 0 > result) {
											/** @type {number} */
											value = value - 3 & 7;
										} else {
											if (0 <= data && 0 <= i && 0 > key && 0 > name && 0 > type) {
												/** @type {number} */
												value = value - 3 & 7;
											} else {
												if (0 <= result && 0 > j && 0 > x && 0 > p) {
													/** @type {number} */
													value = value + 2 & 7;
												} else {
													if (0 <= x && 0 > b && 0 > p && 0 > result) {
														/** @type {number} */
														value = value - 2 & 7;
													}
												}
											}
										}
									}
								}
							}
						}
					} else {
						/** @type {number} */
						var i = obj[index + tags[value] + tags[value + 2 & 7] + tags[value + 3 & 7]];
						if (0 <= i && args[i] != val && args[i] != undefined) {
							/** @type {number} */
							i = -1;
						}
						/** @type {number} */
						index = obj[index + tags[value] + tags[value + 6 & 7] + tags[value + 5 & 7]];
						if (0 <= index && args[index] != val && args[index] != undefined) {
							/** @type {number} */
							index = -1;
						}
						if (0 <= parent && 0 <= p && 0 > j && 0 > g) {
							/** @type {number} */
							value = value + 1 & 7;
						} else {
							if (0 <= j && 0 <= b && 0 > g && 0 > parent) {
								/** @type {number} */
								value = value - 1 & 7;
							} else {
								if (0 <= j && 0 <= result && 0 <= parent && 0 > x && 0 > p) {
									/** @type {number} */
									value = value + 3 & 7;
								} else {
									if (0 <= target && 0 <= type && 0 > data && 0 > key && 0 > name) {
										/** @type {number} */
										value = value + 3 & 7;
									} else {
										if (0 <= data && 0 <= name && 0 > key && 0 > i) {
											/** @type {number} */
											value = value + 3 & 7;
										} else {
											if (0 <= j && 0 <= x && 0 <= parent && 0 > b && 0 > result) {
												/** @type {number} */
												value = value - 3 & 7;
											} else {
												if (0 <= data && 0 <= i && 0 > key && 0 > name && 0 > type) {
													/** @type {number} */
													value = value - 3 & 7;
												} else {
													if (0 <= key && 0 <= type && 0 > name && 0 > index) {
														/** @type {number} */
														value = value - 3 & 7;
													} else {
														if (0 <= parent && 0 > j) {
															/** @type {number} */
															value = value + 2 & 7;
														} else {
															if (0 <= j && 0 > parent) {
																/** @type {number} */
																value = value - 2 & 7;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				} else {
					if (args[j] == _ || args[j] == number || 6 == args[j] || args[j] == line || args[j] == group || args[j] == p) {
						/** @type {number} */
						args[j] = options;
						/** @type {number} */
						arr[j] = 0;
					} else {
						if (args[j] == name || args[j] == r || args[j] == v || args[j] == parent || 37 == args[j] || args[j] == h) {
							/** @type {number} */
							args[j] = title;
							/** @type {number} */
							arr[j] = value + 1;
						} else {
							if (args[j] == key) {
								/** @type {number} */
								args[j] = title;
								/** @type {number} */
								arr[j] = key << 8 | value + 1;
							}
						}
					}
				}
			}
		} else {
			if (j <= temp && 1E3 <= beginHint[max] - k) {
				x = callback(~~params[i].x + varWikidataTypes[value], ~~params[i].y + priorityToColor[value], title);
				if (0 < x) {
					/** @type {number} */
					arr[x] = value + 1;
				}
			}
		}
		/** @type {number} */
		arr[i] = c << 8 | r << 4 | value + 1;
	} else {
		if (args[i] == parent) {
			if (100 <= arr[i]) {
				return call(i), 1;
			}
			items[i].x += 0.2 * values[j].x;
			items[i].y += 0.2 * values[j].y;
			if (obj[index + length] != element) {
				if (obj[index - 1] == element) {
					items[i].x -= clamp(0, 0.1);
				}
				if (obj[index + 1] == element) {
					items[i].x += clamp(0, 0.1);
				}
			}
			items[i].x += clamp(-0.01, 0.01);
			items[i].y += clamp(0.02, 0.05);
			parse(items[i], 0.9);
			a.add(items[i]);
			index = done(i, a);
			value = Number(8);
			x = 5 > value ? index - length : 6 > value ? index - 1 : 7 > value ? index + 1 : index + length;
			/** @type {number} */
			j = obj[x];
			if (0 <= j) {
				if (0 != c1[args[j]]) {
					if (apply(200) < 200 - arr[i]) {
						arr[i] = clamp(arr[i] + c1[args[j]], 0, 100);
						/** @type {number} */
						args[j] = parent;
						/** @type {number} */
						arr[j] = 100;
					}
				} else {
					if (args[j] == none && 0 == map[j]) {
						return arr[j] = 4 | (5 > value ? 2 : 6 > value ? 1 : 7 > value ? 3 : 0), map[j] = parent, call(i), 1;
					}
				}
			}
		} else {
			if (args[i] == p) {
				a.set(items[i]);
				parse(items[i], 0.3);
				index = done(i, a);
				if (1E3 > beginHint[max] - k) {
					return 0;
				}
				if (0 == arr[i]) {
					/** @type {number} */
					c = ~~params[i].x + Number(3) - 1;
					/** @type {number} */
					r = ~~params[i].y - Number(2);
					/** @type {number} */
					x = r * length + c;
					/** @type {number} */
					j = obj[x];
					if (j <= temp) {
						/** @type {number} */
						b = 0;
						for (; 8 > b; b++) {
							if (j = obj[x + topDomains[b]], 0 <= j && args[j] != p && args[j] != group) {
								if (50 > apply(100)) {
									callback(c, r, p);
								}
								break;
							}
						}
					}
					if (obj[index + length] <= temp && obj[index + 2 * length] <= temp && obj[index + length - 1] <= temp && obj[index + length + 1] <= temp && 8 > apply(100)) {
						x = callback(~~params[i].x, ~~params[i].y + 1, p);
						if (0 < x) {
							/** @type {number} */
							arr[x] = 1;
						}
					}
				} else {
					if (1 == arr[i]) {
						if (obj[index + length] <= temp && obj[index + 2 * length] <= temp && obj[index + length - 1] <= temp && obj[index + length + 1] <= temp && 20 > apply(100)) {
							x = callback(~~params[i].x, ~~params[i].y + 1, p);
							if (0 < x) {
								/** @type {number} */
								arr[x] = 1;
							}
						}
						if (4 > apply(100)) {
							/** @type {number} */
							arr[i] = 2;
						}
					}
				}
			} else {
				if (args[i] == size) {
					if (a.y += clamp(0.01, 0.1), a.add(items[i]), parse(items[i], 0.75), index = done(i, a), index = index + (Number(3) - 1), index = index + (Number(3) - 1) * length, j = obj[index], 0 <= j) {
						if (args[j] == name) {
							return args[j] = 37, arr[j] = 0, call(i), 1;
						}
						if (args[j] == object && 50 > apply(100)) {
							return call(i), 1;
						}
					}
				} else {
					if (37 == args[i]) {
						if (items[i].x += 0.2 * values[j].x, items[i].y += 0.2 * values[j].y, obj[index + length] != element && (obj[index - 1] == element && (items[i].x -= clamp(0.1, 0.2)), obj[index + 1] == element && (items[i].x += clamp(0.1, 0.2))), items[i].x += clamp(-0.01, 0.01), items[i].y += 
							 clamp(0.01, 0.05), parse(items[i], 0.9), a.add(items[i]), index = done(i, a), x = index + (Number(5) - 2), x = x + (Number(5) - 2) * length, j = obj[x], 0 <= j && (args[j] == number || 6 == args[j] || args[j] == val) && (args[j] = 
																																																																																	_, arr[j] = 0), value = Number(8), x = 5 > value ? index - length : 6 > value ? index - 1 : 7 > value ? index + 1 : index + length, j = obj[x], 0 <= j) {
							if (7 > value && (1 == hash[args[j]] && args[j] != tag || args[j] == code)) {
								if (10 > apply(100)) {
									iterator(i, j, index, x);
								}
							} else {
								if (args[j] == p) {
									/** @type {number} */
									args[j] = _;
									/** @type {number} */
									arr[j] = 0;
								} else {
									if (args[j] == none && 0 == map[j]) {
										return arr[j] = 4 | (5 > value ? 2 : 6 > value ? 1 : 7 > value ? 3 : 0), map[j] = 37, call(i), 1;
									}
								}
							}
						}
					} else {
						if (args[i] == key) {
							if (0 == arr[i]) {
								if (1 < expect(items[i])) {
									/** @type {number} */
									arr[i] = 1;
								} else {
									cb(items[i], 0, 0);
								}
							} else {
								if (1 == arr[i]) {
									a.set(items[i]);
									/** @type {number} */
									value = 0.5 * get(a);
									if (1 > value) {
										/** @type {number} */
										value = 1;
									}
									/** @type {number} */
									b = 1;
									for (; 6 > b; b++) {
										if (x = ~~(params[i].y + 0.5 + a.y * b) * length + ~~(params[i].x + 0.5 + a.x * b), j = obj[x], 0 <= j) {
											if (args[j] == key) {
												/** @type {number} */
												arr[j] = 1;
												/** @type {number} */
												items[j].x = 0.98 * items[i].x;
												/** @type {number} */
												items[j].y = 0.98 * items[i].y;
											} else {
												break;
											}
										} else {
											break;
										}
									}
									/** @type {number} */
									b = 0;
									for (; 4 > b; b++) {
										x = index + topDomains[b];
										/** @type {number} */
										j = obj[x];
										if (0 <= j && args[j] == key && 0 == arr[j]) {
											/** @type {number} */
											arr[j] = 1;
											r = Number(512);
											/** @type {number} */
											items[j].x = grid[r][0] * value;
											/** @type {number} */
											items[j].y = grid[r][1] * value;
										}
									}
									/** @type {number} */
									args[i] = tag;
									/** @type {number} */
									arr[i] = 0;
								}
							}
							/** @type {number} */
							obj[index] = i;
						} else {
							if (args[i] == node) {
								if (0 == arr[i]) {
									/** @type {number} */
									arr[i] = 1;
									items[i].x = clamp(-1, 1);
									items[i].y = clamp(-1, 1);
								} else {
									if (2 == arr[i]) {
										if (2 > apply(100)) {
											/** @type {number} */
											arr[i] = 1;
											parse(items[i], -1);
										} else {
											return obj[index] = i, 0;
										}
									}
								}
								a.x += 0.5 * items[i].x;
								a.y += 0.5 * items[i].y;
								x = done(i, a);
								if (index == x) {
									if (50 > apply(100)) {
										cb(items[i], items[i].y, -items[i].x);
									} else {
										cb(items[i], -items[i].y, items[i].x);
									}
								}
								index = x;
								x = x + (Number(5) - 2);
								value = Number(5);
								x = x + (value - 2) * length;
								/** @type {number} */
								j = obj[x];
								if (0 <= j) {
									if (3 > value && 2 == hash[args[j]]) {
										iterator(i, j, index, x);
									} else {
										if (args[j] == number || args[j] == group) {
											return args[j] = node, items[j].set(items[i]), arr[j] = 1, call(i), 1;
										}
										if (6 == args[j]) {
											/** @type {number} */
											arr[i] = 2;
										} else {
											if (3 == hash[args[j]]) {
												/** @type {number} */
												args[i] = options;
											}
										}
									}
								}
								/** @type {number} */
								index = 9;
								/** @type {number} */
								b = ~~(params[i].x + 4 * items[i].x);
								/** @type {number} */
								g = ~~(params[i].y + 4 * items[i].y);
								p = max(b - index, width);
								result = max(g - index, width);
								parent = min(b + index, length - width - 1);
								target = min(g + index, (cols - 1) * width - 1);
								cb(a, 0, 0);
								/** @type {number} */
								type = name = key = data = 0;
								r = result;
								for (; r <= target; r++) {
									/** @type {number} */
									x = r * length;
									c = p;
									for (; c <= parent; c++) {
										/** @type {number} */
										value = (c - b) * (c - b) + (r - g) * (r - g);
										if (!(value > index * index)) {
											/** @type {number} */
											j = obj[x + c];
											if (0 <= j) {
												if (args[j] == node) {
													a.x += items[j].x;
													a.y += items[j].y;
													data++;
												} else {
													if (args[j] != number && args[j] != group && 6 != args[j]) {
														key = key + c;
														name = name + r;
														type++;
													}
												}
											} else {
												if (temp < j) {
													key = key + c;
													name = name + r;
													type++;
												}
											}
										}
									}
								}
								if (0 < data) {
									parse(a, 1 / data);
								}
								get(items[i]);
								/** @type {number} */
								items[i].x = 0.5 * items[i].x + 0.5 * a.x;
								/** @type {number} */
								items[i].y = 0.5 * items[i].y + 0.5 * a.y;
								items[i].x += clamp(-0.1, 0.1);
								items[i].y += clamp(-0.1, 0.1);
								if (0 < type) {
									/** @type {number} */
									key = ~~(key / type) - params[i].x;
									/** @type {number} */
									name = ~~(name / type) - params[i].y;
									if (0 > items[i].y * key - items[i].x * name) {
										cb(a, items[i].y, -items[i].x);
									} else {
										cb(a, -items[i].y, items[i].x);
									}
									/** @type {number} */
									items[i].x = 0.9 * items[i].x + 0.1 * a.x;
									/** @type {number} */
									items[i].y = 0.9 * items[i].y + 0.1 * a.y;
								}
							} else {
								if (args[i] == undefined && (items[i].x += 0.2 * values[j].x, items[i].y += 0.2 * values[j].y, obj[index + length] != element && (obj[index - 1] == element && (items[i].x -= clamp(0.1, 0.2)), obj[index + 1] == element && (items[i].x += clamp(0.1, 0.2))), items[i].x += clamp(-0.01, 
																																																																																																			  0.01), items[i].y += clamp(0.01, 0.05), parse(items[i], 0.9), a.add(items[i]), index = done(i, a), value = Number(8), x = 1 > value ? index - length : 2 > value ? index - 1 : 3 > value ? index + 1 : index + length, j = obj[x], 0 <= j)) {
									if (0 < value && (1 == hash[args[j]] || 2 == hash[args[j]] && args[j] != undefined)) {
										iterator(i, j, index, x);
									} else {
										if (args[j] == none && 0 == map[j]) {
											return arr[j] = 4 | (1 > value ? 2 : 2 > value ? 1 : 3 > value ? 3 : 0), map[j] = undefined, call(i), 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
};
/** @type {function(number, !Object): ?} */
msg.fff = e.prototype.G;
/**
 * @param {number} i
 * @param {!Object} s
 * @return {?}
 */
e.prototype.G = function(i, s) {
	var domain;
	var a;
	var index;
	/** @type {number} */
	a = (params[i].y >> 2) * step + (params[i].x >> 2);
	/** @type {number} */
	index = result[i];
	/** @type {number} */
	obj[index] = element;
	s.set(values[a]);
	if (args[i] == event) {
		parse(s, 0.05);
		items[i].add(s);
		items[i].y += 0.01;
		if (-3 <= obj[index + 1]) {
			items[i].x -= apply(0.5);
		}
		if (-3 <= obj[index - 1]) {
			items[i].x += apply(0.5);
		}
		if (-3 <= obj[index + length]) {
			items[i].y -= apply(0.5);
		}
		if (-3 <= obj[index + 2 * length]) {
			items[i].y -= apply(0.5);
		}
		if (-3 <= obj[index - length]) {
			items[i].y += apply(0.5);
		}
		parse(items[i], 0.98);
		s.set(items[i]);
		index = done(i, s);
		index = index + (Number(5) - 2);
		index = index + (Number(5) - 2) * length;
		/** @type {number} */
		var key = obj[index - length];
		if (0 <= key) {
			if (args[key] == _) {
				/** @type {number} */
				args[key] = options;
			} else {
				if (args[key] == name || 37 == args[key] || args[key] == v) {
					return call(i), 1;
				}
				if (11 == args[key]) {
					/** @type {number} */
					args[key] = name;
				} else {
					if (args[key] == group) {
						/** @type {number} */
						args[key] = options;
					}
				}
			}
		}
		if (15 > apply(100)) {
			return call(i), 1;
		}
	} else {
		if (args[i] == action) {
			if (cb(s, 0, 0), index = done(i, s), 256 > arr[i]) {
				index = index + (Number(3) - 1);
				index = index + (Number(3) - 1) * length;
				/** @type {number} */
				key = obj[index];
				if (0 <= key) {
					if (3 == hash[args[key]] && args[key] != event) {
						arr[i] += 256;
					} else {
						if (args[key] == name) {
							/** @type {number} */
							args[i] = message;
						} else {
							if (37 == args[key]) {
								/** @type {number} */
								args[i] = message;
							}
						}
					}
				}
			} else {
				if (arr[i] += 256, 768 <= arr[i]) {
					/** @type {number} */
					a = arr[i] & 255;
					/** @type {number} */
					var val = event;
					if (a == r) {
						/** @type {number} */
						val = options;
					} else {
						if (a == code) {
							/** @type {number} */
							val = code;
						} else {
							if (a == v) {
								/** @type {number} */
								val = n;
							}
						}
					}
					if (0 <= obj[index + 1]) {
						if (obj[index - 1] <= temp) {
							callback(~~params[i].x - 1, ~~params[i].y, val);
						}
						if (obj[index - 1 - length] <= temp) {
							callback(~~params[i].x - 1, ~~params[i].y - 1, val);
						}
						if (obj[index - 1 + length] <= temp) {
							callback(~~params[i].x - 1, ~~params[i].y + 1, val);
						}
					}
					if (0 <= obj[index - 1]) {
						if (obj[index + 1] <= temp) {
							callback(~~params[i].x + 1, ~~params[i].y, val);
						}
						if (obj[index + 1 - length] <= temp) {
							callback(~~params[i].x + 1, ~~params[i].y - 1, val);
						}
						if (obj[index + 1 + length] <= temp) {
							callback(~~params[i].x + 1, ~~params[i].y + 1, val);
						}
					}
					if (0 <= obj[index + length]) {
						if (obj[index - length] <= temp) {
							callback(~~params[i].x, ~~params[i].y - 1, val);
						}
						if (obj[index - 1 - length] <= temp) {
							callback(~~params[i].x - 1, ~~params[i].y - 1, val);
						}
						if (obj[index + 1 - length] <= temp) {
							callback(~~params[i].x + 1, ~~params[i].y - 1, val);
						}
					}
					if (0 <= obj[index - length]) {
						if (obj[index + length] <= temp) {
							callback(~~params[i].x, ~~params[i].y + 1, val);
						}
						if (obj[index - 1 + length] <= temp) {
							callback(~~params[i].x - 1, ~~params[i].y + 1, val);
						}
						if (obj[index + 1 + length] <= temp) {
							callback(~~params[i].x + 1, ~~params[i].y + 1, val);
						}
					}
					/** @type {number} */
					domain = 0;
					for (; 8 > domain; domain++) {
						a = index + topDomains[domain];
						/** @type {number} */
						key = obj[a];
						if (0 <= key) {
							if (args[key] == action && 256 > arr[key]) {
								arr[key] += 256;
							} else {
								if (args[key] == all) {
									items[key].y -= 50;
									arr[key] += 100;
								} else {
									if (args[key] == r) {
										/** @type {number} */
										arr[key] = 1;
									} else {
										if (args[key] == command) {
											/** @type {number} */
											arr[key] = 1;
										} else {
											if (args[key] == code) {
												items[key].y -= 20;
											} else {
												if (args[key] == date) {
													/** @type {number} */
													arr[key] = 1;
												}
											}
										}
									}
								}
							}
						}
					}
					/** @type {number} */
					args[i] = val;
					/** @type {number} */
					arr[i] = 0;
				}
			}
		} else {
			if (args[i] == h) {
				if (s.y += clamp(-0.01, -0.02), s.add(items[i]), parse(items[i], 0.9), index = done(i, s), val = Number(4), a = 1 > val ? index - length : 2 > val ? index - 1 : 3 > val ? index + 1 : index + length, key = obj[a], 0 <= key) {
					if (3 > val && (1 == hash[args[key]] || 2 == hash[args[key]])) {
						iterator(i, key, index, a);
					} else {
						if (args[key] == h) {
							items[i].x += clamp(-0.1, 0.1);
							items[i].y += clamp(-0.1, 0.1);
						} else {
							if (6 == args[key]) {
								/** @type {number} */
								args[i] = name;
							} else {
								if (args[key] == current) {
									/** @type {number} */
									args[i] = 11;
								} else {
									if (args[key] == command) {
										/** @type {number} */
										args[i] = name;
									} else {
										if (args[key] == elem) {
											/** @type {number} */
											args[i] = name;
										} else {
											if (args[key] == val) {
												/** @type {number} */
												args[i] = end;
											} else {
												if (args[key] == p) {
													/** @type {number} */
													args[i] = name;
												} else {
													if (args[key] == action) {
														/** @type {number} */
														args[i] = name;
													} else {
														if (args[key] == none && 0 == map[key]) {
															return arr[key] = 4 | (1 > val ? 2 : 2 > val ? 1 : 3 > val ? 3 : 0), map[key] = name, call(i), 1;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				} else {
					if (-1 == key) {
						/** @type {number} */
						args[i] = name;
					}
				}
			} else {
				if (args[i] == none) {
					cb(s, 0, 0);
					index = done(i, s);
					if (0 == map[i]) {
						return 0;
					}
					/** @type {number} */
					val = arr[i] & 3;
					/** @type {number} */
					var len = arr[i] >> 2;
					/** @type {!Array} */
					var result = [length, -1, -length, 1];
					var mul;
					aL = aL + bL;
					/** @type {number} */
					aL = aL & 1023;
					/** @type {number} */
					mul = 0.5 > positions[aL] ? 1 : -1;
					/** @type {number} */
					domain = 0;
					for (; 4 > domain; domain++) {
						if (2 != domain && (a = index + result[val + domain * mul & 3], key = obj[a], 0 <= key && args[key] == none)) {
							if (0 == map[key]) {
								iterator(i, key, index, a);
								/** @type {number} */
								arr[i] = len << 2 | val + domain * mul & 3;
							} else {
								if (map[i] == map[key]) {
									/** @type {number} */
									val = arr[key] & 3;
									/** @type {number} */
									len = len + (arr[key] >> 2);
									/** @type {number} */
									arr[key] = len << 2 | val;
									/** @type {number} */
									arr[i] = 0;
									/** @type {number} */
									map[i] = 0;
								} else {
									/** @type {number} */
									arr[i] = len << 2 | val + 2 & 3;
								}
							}
							break;
						}
					}
					if (4 == domain) {
						if (obj[index + 2 * result[val]] <= temp && 1E3 <= beginHint[max] - k) {
							index = params[i].x + 0.5;
							a = params[i].y + 0.5;
							if (0 == val) {
								callback(index, a + 2, map[i]);
							} else {
								if (1 == val) {
									callback(index - 2, a, map[i]);
								} else {
									if (2 == val) {
										callback(index, a - 2, map[i]);
									} else {
										if (3 == val) {
											callback(index + 2, a, map[i]);
										}
									}
								}
							}
						}
						if (1 >= len) {
							/** @type {number} */
							arr[i] = 0;
							/** @type {number} */
							map[i] = 0;
						} else {
							/** @type {number} */
							arr[i] = len - 1 << 2 | val;
						}
					}
				}
			}
		}
	}
	return 0;
};
/** @type {function(): undefined} */
msg.fff = e.prototype.A;
/**
 * @return {undefined}
 */
e.prototype.A = function() {
	var i;
	if (6 == i1) {
		/** @type {number} */
		i = 0;
		for (; i < k; i++) {
			/** @type {number} */
			var d = ((settings[args[i]][map[i]] & 16711680) >> 18) + (pixels[result[i]] >> 16 & 255);
			if (255 < d) {
				/** @type {number} */
				d = 255;
			}
			/** @type {number} */
			var e = ((settings[args[i]][map[i]] & 65280) >> 10) + (pixels[result[i]] >> 8 & 255);
			if (255 < e) {
				/** @type {number} */
				e = 255;
			}
			/** @type {number} */
			var b = ((settings[args[i]][map[i]] & 255) >> 2) + (pixels[result[i]] & 255);
			if (255 < b) {
				/** @type {number} */
				b = 255;
			}
			/** @type {number} */
			pixels[result[i]] = d << 16 | e << 8 | b;
		}
	} else {
		if (7 != i1) {
			if (9 == i1) {
				/** @type {number} */
				i = 0;
				for (; i < k; i++) {
					pixels[result[i]] = channels[args[i]];
				}
			} else {
				if (13 == i1) {
					/** @type {number} */
					i = 0;
					for (; i < k; i++) {
						/** @type {number} */
						d = (pixels[result[i]] >> 16 & 255) - (255 - (settings[args[i]][map[i]] >> 16 & 255) + 10);
						if (0 > d) {
							/** @type {number} */
							d = 0;
						}
						/** @type {number} */
						e = (pixels[result[i]] >> 8 & 255) - (255 - (settings[args[i]][map[i]] >> 8 & 255) + 10);
						if (0 > e) {
							/** @type {number} */
							e = 0;
						}
						/** @type {number} */
						b = (pixels[result[i]] & 255) - (255 - (settings[args[i]][map[i]] & 255) + 10);
						if (0 > b) {
							/** @type {number} */
							b = 0;
						}
						/** @type {number} */
						pixels[result[i]] = d << 16 | e << 8 | b;
					}
				} else {
					/** @type {number} */
					i = 0;
					for (; i < k; i++) {
						pixels[result[i]] = settings[args[i]][map[i]];
					}
				}
			}
		}
	}
};
var tmp = new Matrix;
/** @type {number} */
var idx = 0;
/** @type {number} */
var selector = 100;
/** @type {!Array} */
var times = Array(selector);
/** @type {!Array} */
var tokens = Array(selector);
/** @type {!Array} */
var rules = Array(selector);
/** @type {!Array} */
var words = Array(selector);
/** @type {!Array} */
var names = Array(1024);
/** @type {!Array} */
var remainders = Array(1024);
/** @type {!Array} */
var offset = Array(1024);
/** @type {number} */
var j = 0;
/** @type {function(): undefined} */
msg.fff = e.prototype.I;
/**
 * @return {undefined}
 */
e.prototype.I = function() {
	var key;
	var i;
	var idx;
	var s;
	var value;
	var name;
	var width;
	/** @type {!Array} */
	var p = [0, 0, 1, 4, -3, 1, 0, 2, 0, 0, 4, 1, 1, 8, 3, 8, 3, 4, 0, 9, 9, 1, 0, 5, 1, 0, -1, 4, 100, 9, 0, 10, 0, 0, 6, 1, 1, 5, 8, 0, 0, 20, 1, 4, -2, 9];
	if (42 == url && target || 42 == l && cmp) {
		i = new Vector;
		/** @type {number} */
		key = 0;
		for (; key < idx; key++) {
			/** @type {number} */
			i.x = value - times[key];
			/** @type {number} */
			i.y = y - tokens[key];
			if (16 > expect(i)) {
				words[key] -= i.x * (y - g) - i.y * (value - total);
			}
		}
	}
	/** @type {number} */
	key = 0;
	for (; key < idx; key++) {
		/** @type {number} */
		i = (tokens[key] - 16) * length + (times[key] - 16);
		/** @type {number} */
		idx = 32 * parseInt(rules[key]) * tmp.c;
		/** @type {number} */
		value = 0;
		for (; 32 > value; value++, i = i + (length - 32)) {
			/** @type {number} */
			s = 0;
			for (; 32 > s; s++, i++, idx++) {
				if (0 == tmp.b[idx]) {
					/** @type {number} */
					name = (tokens[key] + value - 16 >> 2) * step + (times[key] + s - 16 >> 2);
					/** @type {number} */
					width = values[name].x * (value - 15.5) - values[name].y * (s - 15.5);
					words[key] += 1E-4 * width;
				}
				/** @type {number} */
				name = obj[i];
				if (!(0 > name || 8421504 != tmp.b[idx] || 0 != tmp.b[idx + tmp.c] || 31 == value)) {
					/** @type {number} */
					width = 0 * (value - 15.5) - 1 * (s - 15.5);
					words[key] += width * p[args[name]] * 1E-4;
				}
			}
		}
		words[key] *= 0.99;
		words[key] = clamp(words[key], -2, 2);
		width = parseInt(rules[key] + 16);
		rules[key] += words[key];
		/** @type {number} */
		width = parseInt(rules[key] + 16) - width;
		if (0 > rules[key]) {
			rules[key] += 16;
		}
		if (16 <= rules[key]) {
			rules[key] -= 16;
		}
		if (0 != width) {
			/** @type {number} */
			j = 0;
			/** @type {number} */
			i = (tokens[key] - 16) * length + (times[key] - 16);
			/** @type {number} */
			idx = 32 * parseInt(rules[key]) * tmp.c;
			/** @type {number} */
			value = 0;
			for (; 32 > value; value++, i = i + (length - 32)) {
				/** @type {number} */
				s = 0;
				for (; 32 > s; s++, i++, idx++) {
					if (8421504 == tmp.b[idx]) {
						/** @type {number} */
						name = obj[i];
						if (!(0 > name)) {
							/** @type {number} */
							names[j] = name;
							/** @type {number} */
							remainders[j] = (value - 15.5) * width * 0.1;
							/** @type {number} */
							offset[j] = -(s - 15.5) * width * 0.1;
							j++;
						}
					}
				}
			}
			/** @type {number} */
			i = 0;
			for (; i < j; i++) {
				/** @type {number} */
				obj[result[names[i]]] = element;
				name = parseInt(params[names[i]].y) * length + parseInt(params[names[i]].x + remainders[i]);
				if (-1 > obj[name]) {
					params[names[i]].x += remainders[i];
				}
				name = parseInt(params[names[i]].y + offset[i]) * length + parseInt(params[names[i]].x);
				if (-1 > obj[name]) {
					params[names[i]].y += offset[i];
				}
				result[names[i]] = parseInt(params[names[i]].y) * length + parseInt(params[names[i]].x);
				obj[result[names[i]]] = names[i];
				if (6 == args[names[i]]) {
					if (20 > apply(100)) {
						/** @type {number} */
						args[names[i]] = _;
					}
				} else {
					if (args[names[i]] == current) {
						/** @type {number} */
						args[names[i]] = 11;
					} else {
						if (args[names[i]] == action) {
							/** @type {number} */
							args[names[i]] = message;
						} else {
							if (args[names[i]] == none && 10 > apply(100)) {
								/** @type {number} */
								args[names[i]] = event;
								/** @type {number} */
								map[names[i]] = 0;
							}
						}
					}
				}
			}
		}
	}
};
/** @type {function(): undefined} */
msg.fff = e.prototype.H;
/**
 * @return {undefined}
 */
e.prototype.H = function() {
	var i;
	var idx;
	var id;
	var from;
	var e;
	/** @type {number} */
	var value = 11575440;
	if (13 == i1) {
		/** @type {number} */
		value = 0;
	}
	/** @type {number} */
	i = 0;
	for (; i < idx; i++) {
		/** @type {number} */
		idx = (tokens[i] - 16) * length + (times[i] - 16);
		/** @type {number} */
		id = 32 * parseInt(rules[i]) * tmp.c;
		/** @type {number} */
		e = 0;
		for (; 32 > e; e++, idx = idx + (length - 32)) {
			/** @type {number} */
			from = 0;
			for (; 32 > from; from++, idx++, id++) {
				if (0 == tmp.b[id]) {
					/** @type {number} */
					pixels[idx] = value;
				}
			}
		}
	}
};
/** @type {number} */
var m = 0;
/** @type {number} */
var model = 2E3;
/** @type {!Array} */
var array = Array(model);
/** @type {!Array} */
var pos = Array(model);
/** @type {!Array} */
var o = Array(model);
var content;
var ticksPerBeat;
var w2;
/** @type {!Array} */
var colors = Array(model);
/** @type {function(): undefined} */
msg.fff = e.prototype.r;
/**
 * @return {undefined}
 */
e.prototype.r = function() {
	var j;
	var i;
	var b = new Vector;
	var d;
	/** @type {number} */
	j = 0;
	for (; j < m; j++) {
		/** @type {number} */
		i = (parseInt(pos[j]) >> 2) * step + (parseInt(array[j]) >> 2);
		b.set(values[i]);
		parse(b, 3.8 / (expect(b) + 1));
		array[j] += b.x;
		pos[j] += b.y;
	}
	/** @type {number} */
	j = 0;
	for (; j < m; j++) {
		if (0 == colors[j]) {
			if (42 == url && hasToggledVideo || 42 == l && hasToggledAudio) {
				/** @type {number} */
				b.x = value - array[j];
				/** @type {number} */
				b.y = y - pos[j];
				if (10 > expect(b)) {
					/** @type {number} */
					colors[j] = 1;
				}
			}
		} else {
			if (42 == url && target || 42 == l && cmp) {
				array[j] += 0.9 * (value - array[j]);
				pos[j] += 0.9 * (y - pos[j]);
			} else {
				/** @type {number} */
				colors[j] = 0;
			}
		}
	}
	/** @type {number} */
	j = 0;
	for (; j < m - 1;) {
		d = o[j];
		/** @type {number} */
		var a = 0;
		/** @type {number} */
		i = j;
		for (; i < m && d == o[i]; i++, a++) {
		}
		cb(b, 0, 0);
		/** @type {number} */
		i = j;
		for (; i < j + a; i++) {
			b.x += array[i];
			b.y += pos[i];
		}
		i = b;
		/** @type {number} */
		d = a;
		i.x /= d;
		i.y /= d;
		/** @type {number} */
		i = j;
		for (; i < j + a; i++) {
			var t = new Vector;
			/** @type {number} */
			t.x = b.x - array[i];
			/** @type {number} */
			t.y = b.y - pos[i];
			d = get(t);
			if (0 != d) {
				/** @type {number} */
				d = a * w2 - d;
				array[i] -= t.x * d * 0.1;
				pos[i] -= t.y * d * 0.1;
			}
		}
		/** @type {number} */
		i = j;
		for (; i < j + a - 1; i++) {
			find(i, i + 1);
		}
		find(i, j);
		/** @type {number} */
		j = j + a;
	}
	/** @type {number} */
	j = 0;
	for (; j < m; j++) {
		/** @type {number} */
		i = 0;
		if (0 <= array[j] && array[j] < length && 0 <= pos[j] && 316 > pos[j]) {
			i = parseInt(pos[j]) * length + parseInt(array[j]);
			if (obj[i] <= temp) {
				continue;
			}
			if (0 <= obj[i] && args[obj[i]] == v) {
				continue;
			}
		}
		d = o[j];
		/** @type {number} */
		b = j;
		for (; 0 < b && d == o[b - 1]; b--) {
		}
		/** @type {number} */
		a = b + 1;
		for (; a < m && d == o[a]; a++) {
		}
		/** @type {number} */
		j = obj[i];
		/** @type {number} */
		j = 0 <= j ? args[j] : n;
		/** @type {number} */
		i = b;
		for (; i < a - 1; i++) {
			compare(array[i], pos[i], array[i + 1], pos[i + 1], j);
		}
		compare(array[i], pos[i], array[b], pos[b], j);
		/** @type {number} */
		j = b - 1;
		for (; a < m; b++, a++) {
			array[b] = array[a];
			pos[b] = pos[a];
			o[b] = o[a];
			colors[b] = colors[a];
		}
		/** @type {number} */
		m = m - (a - b);
	}
};
/** @type {function(): undefined} */
msg.fff = e.prototype.q;
/**
 * @return {undefined}
 */
e.prototype.q = function() {
	var i;
	/** @type {!Array} */
	var deletedHashes = [16769248, 16773344, 16777184, 14745568, 14745599, 14741759, 14737663, 16769279];
	if (13 == i1) {
		/** @type {!Array} */
		deletedHashes = [0, 0, 0, 0, 0, 0, 0, 0];
	}
	/** @type {number} */
	var hash = 0;
	/** @type {number} */
	i = 0;
	for (; i < m - 1; i++) {
		/** @type {number} */
		var p = i;
		var a = o[i];
		for (; i < m - 1 && a == o[i + 1]; i++) {
			add(array[i], pos[i], array[i + 1], pos[i + 1], deletedHashes[hash]);
			hash++;
			/** @type {number} */
			hash = hash & 7;
		}
		add(array[i], pos[i], array[p], pos[p], deletedHashes[hash]);
		hash++;
		/** @type {number} */
		hash = hash & 7;
	}
};
/** @type {number} */
var to = 0;
/** @type {number} */
var from = 50;
/** @type {number} */
var stride = 28;
/** @type {!Array} */
var vertices = Array(from * stride);
/** @type {!Array} */
var row = Array(from * stride);
/** @type {!Array} */
var keys = Array(from * stride);
/** @type {!Array} */
var messages = Array(from);
/** @type {!Array} */
var rows = Array(from);
/** @type {!Array} */
var children = Array(from);
/** @type {!Array} */
var lines = Array(from);
/** @type {!Array} */
var list = Array(from);
/** @type {!Array} */
var g_board = Array(from);
/** @type {number} */
to = 0;
for (; to < from * stride; to++) {
	vertices[to] = new Vector;
}
/** @type {number} */
to = 0;
for (; to < from * stride; to++) {
	row[to] = new Vector;
}
/** @type {number} */
to = 0;
for (; to < from; to++) {
	messages[to] = new Vector;
}
/** @type {!Array} */
var scales = [0, 0.5, 0.5, 0.8, 1, 0.5, 0.5, 0.5, 1, 0.5, 1, 0.5, 1, 0.5, 0.5, 0.5, 0.8, 0.5, 0, 0.5, 0.5, 0.5, 0, 0.8, 0.5, 0, 1, 1, 0, 0.5, 0, 0.5, 0, 0, 0.8, 0.5, 0.5, 0.8, 0.9, 0.1, 0, 1, 0.5, 0.5, 1, 0.5];
/** @type {!Array} */
var props = [0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0];
/** @type {number} */
var item = 10;
/** @type {number} */
var tr = 20;
/** @type {number} */
var float = 30;
/** @type {number} */
var auto = 40;
/** @type {!Array} */
var rulesFrom = [0, 0];
/** @type {!Array} */
var m_players = [0, 0];
/** @type {!Array} */
var messageDomIds = [0, 0];
/** @type {function(): undefined} */
msg.fff = e.prototype.w;
/**
 * @return {undefined}
 */
e.prototype.w = function() {
	/** @type {number} */
	var start = 0;
	for (; start < to; start++) {
		/** @type {number} */
		var i = start;
		var x = void 0;
		var index = void 0;
		var p = new Vector;
		/** @type {number} */
		index = i * stride;
		if (rows[i] == float) {
			var a = 0 == g_board[i] ? pairs[37] : pairs[65] | pairs[97];
			var sX = 0 == g_board[i] ? pairs[39] : pairs[68] | pairs[100];
			var sY = 0 == g_board[i] ? pairs[38] : pairs[87] | pairs[119];
			var found = 0 == g_board[i] ? pairs[40] : pairs[83] | pairs[115];
			/** @type {number} */
			var j = 0 == g_board[i] ? 0 : 1;
			children[i]++;
			/** @type {number} */
			var y = obj[(parseInt(row[index + 4].y) + 1) * length + parseInt(row[index + 4].x)] > temp ? 1 : 0;
			/** @type {number} */
			var key = obj[(parseInt(row[index + 5].y) + 1) * length + parseInt(row[index + 5].x)] > temp ? 1 : 0;
			if (0 == y) {
				/** @type {number} */
				y = obj[parseInt(row[index + 4].y) * length + parseInt(row[index + 4].x)] > temp ? 1 : 0;
			}
			if (0 == key) {
				/** @type {number} */
				key = obj[parseInt(row[index + 5].y) * length + parseInt(row[index + 5].x)] > temp ? 1 : 0;
			}
			if (found && list[i] == node) {
				/** @type {number} */
				x = 0;
				for (; 6 > x; x++) {
					remove(index + x, 0.01, 0.997);
				}
			} else {
				remove(index + 0, -0.2, 0.995);
				remove(index + 1, -0.1, 0.995);
				remove(index + 2, 0, 0.995);
				remove(index + 3, 0, 0.995);
				remove(index + 4, 0.3, 0.995);
				remove(index + 5, 0.3, 0.995);
			}
			vertices[index].add(messages[i]);
			parse(messages[i], 0.5);
			if (0 != messages[i].x) {
				/** @type {number} */
				rows[i] = float + 2;
			}
			if (0 < rulesFrom[j]) {
				rulesFrom[j]--;
			}
			if (0 != rulesFrom[j] || 1 != y && 1 != key) {
				if (sX) {
					if (0 > vertices[index + 1].x - row[index + 1].x) {
						vertices[index + 1].x += 0.1;
					}
					/** @type {number} */
					messageDomIds[j] = 1;
				} else {
					if (a) {
						if (0 < vertices[index + 1].x - row[index + 1].x) {
							vertices[index + 1].x -= 0.1;
						}
						/** @type {number} */
						messageDomIds[j] = 0;
					}
				}
			} else {
				/** @type {number} */
				x = 0.8;
				if (sX) {
					/** @type {number} */
					rulesFrom[j] = 15;
					if (vertices[index + 4].x < vertices[index + 5].x) {
						vertices[index + 2].x += 4 * x;
						vertices[index + 2].y -= 3 * x;
					} else {
						vertices[index + 3].x += 4 * x;
						vertices[index + 3].y -= 3 * x;
					}
					/** @type {number} */
					messageDomIds[j] = 1;
				} else {
					if (a) {
						/** @type {number} */
						rulesFrom[j] = 15;
						if (vertices[index + 4].x > vertices[index + 5].x) {
							vertices[index + 2].x -= 4 * x;
							vertices[index + 2].y -= 3 * x;
						} else {
							vertices[index + 3].x -= 4 * x;
							vertices[index + 3].y -= 3 * x;
						}
						/** @type {number} */
						messageDomIds[j] = 0;
					}
				}
			}
			if (1 < m_players[j]) {
				m_players[j]--;
			}
			if (0 < m_players[j] && (1 == y || 1 == key)) {
				m_players[j]--;
			}
			if (0 == m_players[j] && sY) {
				/** @type {number} */
				m_players[j] = 50;
				vertices[index + 4].y -= 6;
				vertices[index + 5].y -= 6;
			}
			/** @type {number} */
			x = 0.5;
			verify(index + 0, index + 1, 4, x, x);
			verify(index + 1, index + 2, 4, x, x);
			verify(index + 1, index + 3, 4, x, x);
			verify(index + 2, index + 4, 5, x, x);
			verify(index + 3, index + 5, 5, x, x);
			verify(index + 2, index + 3, 5, 0.1, 0.1);
			/** @type {number} */
			y = 0.1;
			/** @type {number} */
			x = 0;
			for (; 4 > x; x++) {
				f(index + x, y, 1, 0 < lines[i] ? 1 : 0);
			}
			/** @type {number} */
			x = 4;
			for (; 6 > x; x++) {
				f(index + x, y, 0, 0 < lines[i] ? 1 : 0);
			}
			/** @type {number} */
			x = 0;
			for (; 3 > x; x++) {
				/** @type {number} */
				y = -1;
				for (; 2 > y; y++) {
					/** @type {number} */
					key = obj[(parseInt(row[index + 0].y) + x) * length + (parseInt(row[index + 0].x) + y)];
					if (key == temp) {
						/** @type {number} */
						list[i] = id;
					} else {
						if (0 <= key && 1 == props[args[key]]) {
							/** @type {number} */
							list[i] = args[key];
						}
					}
				}
			}
			if (!(sY && (a || sX) || !found || 0 == list[i])) {
				y = parseInt(vertices[index + 0].x);
				x = parseInt(vertices[index + 0].y) + 1;
				if (list[i] == code) {
					y = y + (0 == messageDomIds[j] ? 8 : -8);
					x = x + 12;
				}
				y = clamp(y, 8, 407);
				x = clamp(x, 8, 307);
				if (list[i] == id) {
					/** @type {number} */
					a = (x >> 2) * step + (y >> 2);
					if (0 == out[a]) {
						values[a].x += 0 == messageDomIds[j] ? -1 : 1;
					}
				} else {
					if (list[i] != node && obj[x * length + y] == element) {
						a = callback(y, x, list[i]);
						if (0 <= a) {
							if (0 == messageDomIds[j]) {
								items[a].x -= 20;
								items[a].y += apply(3) - 1;
							} else {
								if (1 == messageDomIds[j]) {
									items[a].x += 20;
									items[a].y += apply(3) - 1;
								}
							}
							if (list[i] == options) {
								items[a].x *= 3;
								items[a].y += 18;
								/** @type {number} */
								arr[a] = 2;
							} else {
								if (list[i] == line) {
									/** @type {number} */
									items[a].y = 20;
								} else {
									if (list[i] == tag) {
										items[a].x *= 0.1;
										items[a].y *= 0.1;
									} else {
										if (list[i] == title) {
											/** @type {number} */
											arr[a] = 0 == messageDomIds[j] ? 5 : 1;
										}
									}
								}
							}
						}
					}
				}
			}
			if (3 == label(index, index + 6) || -5 == label(index, index + 6)) {
				/** @type {number} */
				rows[i] = float + 2;
			}
			if (1 == option) {
				/** @type {number} */
				j = 4;
				for (; 5 >= j; j++) {
					if (y = x = 0, 8 > vertices[index + j].x ? (y = 406, x = parseInt(row[index + j].y)) : length - 8 <= vertices[index + j].x && (y = 10, x = parseInt(row[index + j].y)), 0 != y + x) {
						/** @type {number} */
						rows[i] = float;
						/** @type {number} */
						a = x * length + y;
						if (!(obj[a] <= temp)) {
							if (-1 >= obj[a]) {
								vertices[index + j].set(row[index + j]);
								continue;
							} else {
								if (2 != hash[args[obj[a]]]) {
									vertices[index + j].set(row[index + j]);
									continue;
								}
							}
						}
						equals(p, vertices[index + j], row[index + j]);
						get(p);
						/** @type {number} */
						i = 0;
						for (; 10 >= i; i++) {
							vertices[index + i].x = y + p.x + clamp(-0.1, 0.1);
							vertices[index + i].y = x + p.y + clamp(-0.1, 0.1);
							cb(row[index + i], y, x);
						}
						break;
					}
				}
			}
		} else {
			if (rows[i] == float + 2) {
				vertices[index + 10].set(vertices[index + 5]);
				row[index + 10].set(row[index + 5]);
				vertices[index + 9].set(vertices[index + 4]);
				row[index + 9].set(row[index + 4]);
				vertices[index + 8].set(vertices[index + 3]);
				row[index + 8].set(row[index + 3]);
				vertices[index + 7].set(vertices[index + 3]);
				row[index + 7].set(row[index + 3]);
				vertices[index + 6].set(vertices[index + 2]);
				row[index + 6].set(row[index + 2]);
				vertices[index + 5].set(vertices[index + 2]);
				row[index + 5].set(row[index + 2]);
				vertices[index + 4].set(vertices[index + 1]);
				row[index + 4].set(row[index + 1]);
				vertices[index + 3].set(vertices[index + 1]);
				row[index + 3].set(row[index + 1]);
				vertices[index + 2].set(vertices[index + 1]);
				row[index + 2].set(row[index + 1]);
				vertices[index + 1].set(vertices[index + 0]);
				row[index + 1].set(row[index + 0]);
				vertices[index + 0].set(vertices[index + 0]);
				row[index + 0].set(row[index + 0]);
				messages[i].y -= 1;
				/** @type {number} */
				children[i] = 0;
				/** @type {number} */
				rows[i] = float + 3;
			} else {
				if (rows[i] == float + 3) {
					children[i]++;
					/** @type {number} */
					x = 0;
					for (; 11 > x; x++) {
						remove(index + x, 0.1, 0.999);
						vertices[index + x].add(messages[i]);
					}
					parse(messages[i], 0.5);
					/** @type {number} */
					x = 0.5;
					/** @type {number} */
					p = (150 - children[i]) / 150;
					verify(index + 1, index + 2, 4 * p, x, x);
					verify(index + 3, index + 5, 4 * p, x, x);
					verify(index + 4, index + 7, 4 * p, x, x);
					verify(index + 6, index + 9, 5 * p, x, x);
					verify(index + 8, index + 10, 5 * p, x, x);
					/** @type {number} */
					y = 0.1;
					/** @type {number} */
					x = 0;
					for (; 11 > x; x++) {
						f(index + x, y, 0, 0);
					}
					if (150 < children[i]) {
						split(i--);
					}
				} else {
					if (rows[i] == item || rows[i] == item + 1) {
						children[i]++;
						if (rows[i] == item) {
							remove(index + 0, -0.2, 0.995);
							remove(index + 1, -0.1, 0.995);
							remove(index + 2, 0, 0.995);
							remove(index + 3, 0, 0.995);
							remove(index + 4, 0.3, 0.995);
							remove(index + 5, 0.3, 0.995);
						} else {
							remove(index + 0, 0.1, 0.995);
							remove(index + 1, 0.1, 0.995);
							remove(index + 2, 0.1, 0.995);
							remove(index + 3, 0.1, 0.995);
							remove(index + 4, 0.1, 0.995);
							remove(index + 5, 0.1, 0.995);
						}
						match(i, index, index + 6);
						vertices[index].add(messages[i]);
						parse(messages[i], 0.5);
						if (rows[i] == item) {
							if (0 != keys[index + 4] && 0 != keys[index + 5]) {
								j = parseInt(apply(100));
								if (5 > j) {
									if (vertices[index + 4].x < vertices[index + 5].x) {
										vertices[index + 4].x += 4;
										vertices[index + 4].y -= 4;
									} else {
										vertices[index + 5].x += 4;
										vertices[index + 5].y -= 4;
									}
								} else {
									if (10 > j) {
										if (vertices[index + 4].x > vertices[index + 5].x) {
											vertices[index + 4].x -= 4;
											vertices[index + 4].y -= 4;
										} else {
											vertices[index + 5].x -= 4;
											vertices[index + 5].y -= 4;
										}
									}
								}
							} else {
								if (0 != keys[index + 4]) {
									if (2 > apply(100)) {
										vertices[index + 4].x += clamp(-4, 4);
										vertices[index + 4].y -= 4;
									}
								} else {
									if (0 != keys[index + 5] && 2 > apply(100)) {
										vertices[index + 5].x += clamp(-4, 4);
										vertices[index + 5].y -= 4;
									}
								}
							}
							j = void 0;
							/** @type {number} */
							j = 0;
							for (; j < to; j++) {
								if (!(i == j || rows[j] != item && rows[j] != item + 1 && rows[j] != float)) {
									/** @type {number} */
									a = j * stride;
									sX = abs(vertices[index + 4].x - vertices[a].x);
									/** @type {number} */
									sY = vertices[index + 4].y - vertices[a].y;
									if (2 >= sX && 0 <= sY && 6 >= sY) {
										messages[j].x += 1 * (vertices[index + 4].x - row[index + 4].x);
										messages[j].y += 2 * (vertices[index + 4].y - row[index + 4].y);
										if (rows[j] == item) {
											/** @type {number} */
											rows[j] = item + 1;
										}
										/** @type {number} */
										children[j] = 0;
									}
									sX = abs(vertices[index + 5].x - vertices[a].x);
									/** @type {number} */
									sY = vertices[index + 5].y - vertices[a].y;
									if (2 >= sX && 0 <= sY && 6 >= sY) {
										messages[j].x += 1 * (vertices[index + 5].x - row[index + 5].x);
										messages[j].y += 2 * (vertices[index + 5].y - row[index + 5].y);
										if (rows[j] == item) {
											/** @type {number} */
											rows[j] = item + 1;
										}
										/** @type {number} */
										children[j] = 0;
									}
								}
							}
						} else {
							if (10 < children[i] && (0 != keys[index + 4] || 0 != keys[index + 5]) && 10 > apply(100)) {
								/** @type {number} */
								rows[i] = item;
								/** @type {number} */
								children[i] = 0;
							}
						}
						/** @type {number} */
						x = 0.5;
						verify(index + 0, index + 1, 4, x, x);
						verify(index + 1, index + 2, 4, x, x);
						verify(index + 1, index + 3, 4, x, x);
						verify(index + 2, index + 4, 5, x, x);
						verify(index + 3, index + 5, 5, x, x);
						verify(index + 2, index + 3, 5, 0.1, 0.1);
						/** @type {number} */
						y = 0.1;
						/** @type {number} */
						x = 0;
						for (; 4 > x; x++) {
							f(index + x, y, 1, 0 < lines[i] ? 1 : 0);
						}
						/** @type {number} */
						x = 4;
						for (; 6 > x; x++) {
							f(index + x, y, 0, 0 < lines[i] ? 1 : 0);
						}
						if (3 == label(index, index + 6) || -5 == label(index, index + 6)) {
							/** @type {number} */
							rows[i] = item + 2;
						}
						if (rows[i] == item) {
							if (0 != label(index, index + 6)) {
								/** @type {number} */
								children[i] = 0;
							} else {
								if (50 < children[i]) {
									/** @type {number} */
									rows[i] = item + 1;
								}
							}
						}
						if (1 == option) {
							/** @type {number} */
							j = 4;
							for (; 5 >= j; j++) {
								if (y = x = 0, 8 > vertices[index + j].x ? (y = 406, x = parseInt(row[index + j].y)) : length - 8 <= vertices[index + j].x && (y = 10, x = parseInt(row[index + j].y)), 0 != y + x) {
									/** @type {number} */
									rows[i] = item;
									/** @type {number} */
									children[i] = 0;
									/** @type {number} */
									a = x * length + y;
									if (!(obj[a] <= temp)) {
										if (-1 >= obj[a]) {
											vertices[index + j].set(row[index + j]);
											continue;
										} else {
											if (2 != hash[args[obj[a]]]) {
												vertices[index + j].set(row[index + j]);
												continue;
											}
										}
									}
									equals(p, vertices[index + j], row[index + j]);
									get(p);
									/** @type {number} */
									i = 0;
									for (; 10 >= i; i++) {
										vertices[index + i].x = y + p.x + clamp(-0.1, 0.1);
										vertices[index + i].y = x + p.y + clamp(-0.1, 0.1);
										cb(row[index + i], y, x);
									}
									break;
								}
							}
						}
					} else {
						if (rows[i] == item + 2) {
							vertices[index + 10].set(vertices[index + 5]);
							row[index + 10].set(row[index + 5]);
							vertices[index + 9].set(vertices[index + 4]);
							row[index + 9].set(row[index + 4]);
							vertices[index + 8].set(vertices[index + 3]);
							row[index + 8].set(row[index + 3]);
							vertices[index + 7].set(vertices[index + 3]);
							row[index + 7].set(row[index + 3]);
							vertices[index + 6].set(vertices[index + 2]);
							row[index + 6].set(row[index + 2]);
							vertices[index + 5].set(vertices[index + 2]);
							row[index + 5].set(row[index + 2]);
							vertices[index + 4].set(vertices[index + 1]);
							row[index + 4].set(row[index + 1]);
							vertices[index + 3].set(vertices[index + 1]);
							row[index + 3].set(row[index + 1]);
							vertices[index + 2].set(vertices[index + 1]);
							row[index + 2].set(row[index + 1]);
							vertices[index + 1].set(vertices[index + 0]);
							row[index + 1].set(row[index + 0]);
							vertices[index + 0].set(vertices[index + 0]);
							row[index + 0].set(row[index + 0]);
							messages[i].y -= 1;
							/** @type {number} */
							children[i] = 0;
							/** @type {number} */
							rows[i] = item + 3;
						} else {
							if (rows[i] == item + 3) {
								children[i]++;
								/** @type {number} */
								x = 0;
								for (; 11 > x; x++) {
									remove(index + x, 0.1, 0.999);
									vertices[index + x].add(messages[i]);
								}
								parse(messages[i], 0.5);
								/** @type {number} */
								x = 0.5;
								/** @type {number} */
								p = (150 - children[i]) / 150;
								verify(index + 1, index + 2, 4 * p, x, x);
								verify(index + 3, index + 5, 4 * p, x, x);
								verify(index + 4, index + 7, 4 * p, x, x);
								verify(index + 6, index + 9, 5 * p, x, x);
								verify(index + 8, index + 10, 5 * p, x, x);
								/** @type {number} */
								y = 0.1;
								/** @type {number} */
								x = 0;
								for (; 11 > x; x++) {
									f(index + x, y, 0, 0);
								}
								if (150 < children[i]) {
									split(i--);
								}
							} else {
								if (rows[i] == tr) {
									children[i]++;
									/** @type {number} */
									x = 0;
									for (; 4 > x; x++) {
										remove(index + x, 0.1, 1);
									}
									match(i, index, index + 4);
									/** @type {number} */
									x = 0;
									for (; 4 > x; x++) {
										/** @type {number} */
										j = 0;
										for (; j < to; j++) {
											if (rows[j] == item || rows[j] == item + 1 || rows[j] == float) {
												/** @type {number} */
												a = j * stride;
												sX = abs(vertices[a + 4].x - vertices[index + x].x);
												sY = abs(vertices[a + 4].y - vertices[index + x].y);
												if (3 >= sX && 3 >= sY) {
													vertices[index + x].x += 1 * (vertices[a + 4].x - row[a + 4].x);
													vertices[index + x].y += 2 * (vertices[a + 4].y - row[a + 4].y);
												}
												sX = abs(vertices[a + 5].x - vertices[index + x].x);
												sY = abs(vertices[a + 5].y - vertices[index + x].y);
												if (3 >= sX && 3 >= sY) {
													vertices[index + x].x += 1 * (vertices[a + 5].x - row[a + 5].x);
													vertices[index + x].y += 2 * (vertices[a + 5].y - row[a + 5].y);
												}
											}
										}
									}
									/** @type {number} */
									x = 0.5;
									/** @type {number} */
									j = 4 * (list[i] + 1);
									verify(index + 0, index + 1, j, x, x);
									verify(index + 1, index + 2, j, x, x);
									verify(index + 2, index + 3, j, x, x);
									verify(index + 3, index + 0, j, x, x);
									verify(index + 0, index + 2, 1.4142135 * j, x, x);
									verify(index + 1, index + 3, 1.4142135 * j, x, x);
									/** @type {number} */
									y = 0.5;
									/** @type {number} */
									x = 0;
									for (; 4 > x; x++) {
										f(index + x, y, 0, 1);
									}
									if (3 == label(index, index + 6) || -5 == label(index, index + 6)) {
										/** @type {number} */
										rows[i] = tr + 1;
									}
								} else {
									if (rows[i] == tr + 1) {
										vertices[index + 7].set(vertices[index + 0]);
										row[index + 7].set(row[index + 0]);
										vertices[index + 6].set(vertices[index + 3]);
										row[index + 6].set(row[index + 3]);
										vertices[index + 5].set(vertices[index + 3]);
										row[index + 5].set(row[index + 3]);
										vertices[index + 4].set(vertices[index + 2]);
										row[index + 4].set(row[index + 2]);
										vertices[index + 3].set(vertices[index + 2]);
										row[index + 3].set(row[index + 2]);
										vertices[index + 2].set(vertices[index + 1]);
										row[index + 2].set(row[index + 1]);
										vertices[index + 1].set(vertices[index + 1]);
										row[index + 1].set(row[index + 1]);
										vertices[index + 0].set(vertices[index + 0]);
										row[index + 0].set(row[index + 0]);
										/** @type {number} */
										lines[i] = 0;
										/** @type {number} */
										children[i] = 0;
										/** @type {number} */
										rows[i] = -5 == label(index, index + 4) ? tr + 3 : tr + 2;
									} else {
										if (rows[i] == tr + 2 || rows[i] == tr + 3) {
											children[i]++;
											match(i, index, index + 8);
											/** @type {number} */
											x = 0;
											for (; 8 > x; x++) {
												remove(index + x, 0.1, 0.999);
											}
											/** @type {number} */
											x = 0.5;
											/** @type {number} */
											j = (150 - children[i]) / 150 * (list[i] + 1) * 4;
											verify(index + 0, index + 1, j, x, x);
											verify(index + 2, index + 3, j, x, x);
											verify(index + 4, index + 5, j, x, x);
											verify(index + 6, index + 7, j, x, x);
											if (rows[i] == tr + 2 && 1E3 <= beginHint[max] - k) {
												/** @type {number} */
												x = 0;
												for (; 8 > x; x = x + 2) {
													equals(p, row[index + x + 1], row[index + x]);
													parse(p, apply(1));
													p.add(row[index + x]);
													a = parseInt(p.y) * length + parseInt(p.x);
													if (obj[a] <= temp) {
														callback(parseInt(p.x), parseInt(p.y), options);
													}
												}
											}
											/** @type {number} */
											y = 0.1;
											/** @type {number} */
											x = 0;
											for (; 8 > x; x++) {
												f(index + x, y, 0, 0);
											}
											if (150 < children[i]) {
												split(i--);
											}
										} else {
											if (rows[i] == auto) {
												if (0 == keys[index]) {
													/** @type {number} */
													j = 0;
													for (; j < to; j++) {
														if (!(vertices[index].x + 8 < vertices[j * stride].x || vertices[j * stride].x < vertices[index].x - 4 || vertices[index].y + 8 < vertices[j * stride].y || vertices[j * stride].y < vertices[index].y - 4)) {
															if (rows[j] == item || rows[j] == tr) {
																keys[index] = rows[j];
																list[i] = list[j];
															} else {
																if (rows[j] == float) {
																	/** @type {number} */
																	p = 0;
																	for (; p < to; p++) {
																		if (rows[p] == auto && keys[p * stride] == float) {
																			/** @type {number} */
																			keys[p * stride] = 0;
																		}
																	}
																	keys[index] = rows[j];
																	list[i] = list[j];
																}
															}
														}
													}
													/** @type {number} */
													j = 0;
													for (; j < _len; j++) {
														if (!(0 == plugins[j] || vertices[index].x + 8 < objects[j].x || objects[j].x < vertices[index].x - 4 || vertices[index].y + 8 < objects[j].y || objects[j].y < vertices[index].y - 4)) {
															/** @type {number} */
															keys[index] = -2;
															list[i] = data[j];
														}
													}
												} else {
													y = parseInt(vertices[index + 0].x);
													x = parseInt(vertices[index + 0].y);
													if (keys[index] == float) {
														if (10 > apply(100)) {
															log(y, x, 30, list[i]);
														}
													} else {
														if (1 > apply(100)) {
															if (keys[index] == item) {
																log(y, x, 0, 0);
															} else {
																if (keys[index] == tr) {
																	log(y, x, 22, list[i]);
																} else {
																	if (-2 == keys[index]) {
																		func(y + 2, x + 2, list[i]);
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
};
/** @type {function(): undefined} */
msg.fff = e.prototype.v;
/**
 * @return {undefined}
 */
e.prototype.v = function() {
	var i;
	var start;
	var j;
	/** @type {number} */
	var data = 16769198;
	/** @type {number} */
	var selector = 16777215;
	if (13 == i1) {
		/** @type {number} */
		selector = data = 0;
	}
	/** @type {number} */
	i = 0;
	for (; i < to; i++) {
		/** @type {number} */
		j = i * stride;
		switch(rows[i]) {
		case item:
		case item + 1:
		case item + 2:
			add(vertices[j + 0].x, vertices[j + 0].y, vertices[j + 1].x, vertices[j + 1].y, data);
			add(vertices[j + 1].x, vertices[j + 1].y, vertices[j + 2].x, vertices[j + 2].y, selector);
			add(vertices[j + 1].x, vertices[j + 1].y, vertices[j + 3].x, vertices[j + 3].y, selector);
			add(vertices[j + 2].x, vertices[j + 2].y, vertices[j + 4].x, vertices[j + 4].y, selector);
			add(vertices[j + 3].x, vertices[j + 3].y, vertices[j + 5].x, vertices[j + 5].y, selector);
			drawLine(parseInt(vertices[j + 0].x) - 1, parseInt(vertices[j + 0].y) - 1, 3, 3, data);
			break;
		case item + 3:
			add(vertices[j + 1].x, vertices[j + 1].y, vertices[j + 2].x, vertices[j + 2].y, selector);
			if (145 < children[i]) {
				break;
			}
			add(vertices[j + 3].x, vertices[j + 3].y, vertices[j + 5].x, vertices[j + 5].y, selector);
			if (140 < children[i]) {
				break;
			}
			add(vertices[j + 4].x, vertices[j + 4].y, vertices[j + 7].x, vertices[j + 7].y, selector);
			if (135 < children[i]) {
				break;
			}
			add(vertices[j + 6].x, vertices[j + 6].y, vertices[j + 9].x, vertices[j + 9].y, selector);
			if (130 < children[i]) {
				break;
			}
			add(vertices[j + 8].x, vertices[j + 8].y, vertices[j + 10].x, vertices[j + 10].y, selector);
			if (125 < children[i]) {
				break;
			}
			drawLine(parseInt(vertices[j + 0].x) - 1, parseInt(vertices[j + 0].y) - 1, 2, 2, data);
			break;
		case tr:
		case tr + 1:
			add(vertices[j + 0].x, vertices[j + 0].y, vertices[j + 1].x, vertices[j + 1].y, data);
			add(vertices[j + 1].x, vertices[j + 1].y, vertices[j + 2].x, vertices[j + 2].y, data);
			add(vertices[j + 2].x, vertices[j + 2].y, vertices[j + 3].x, vertices[j + 3].y, data);
			add(vertices[j + 3].x, vertices[j + 3].y, vertices[j + 0].x, vertices[j + 0].y, data);
			break;
		case tr + 2:
		case tr + 3:
			add(vertices[j + 0].x, vertices[j + 0].y, vertices[j + 1].x, vertices[j + 1].y, data);
			if (145 < children[i]) {
				break;
			}
			add(vertices[j + 2].x, vertices[j + 2].y, vertices[j + 3].x, vertices[j + 3].y, data);
			if (140 < children[i]) {
				break;
			}
			add(vertices[j + 4].x, vertices[j + 4].y, vertices[j + 5].x, vertices[j + 5].y, data);
			if (135 < children[i]) {
				break;
			}
			add(vertices[j + 6].x, vertices[j + 6].y, vertices[j + 7].x, vertices[j + 7].y, data);
			if (130 < children[i]) {
				break;
			}
			break;
		case float:
		case float + 2:
		case float + 3:
			var n;
			var p;
			var e;
			var z;
			if (rows[i] != float + 3) {
				add(vertices[j + 1].x, vertices[j + 1].y, vertices[j + 2].x, vertices[j + 2].y, selector);
				add(vertices[j + 1].x, vertices[j + 1].y, vertices[j + 3].x, vertices[j + 3].y, selector);
				add(vertices[j + 2].x, vertices[j + 2].y, vertices[j + 4].x, vertices[j + 4].y, selector);
				add(vertices[j + 3].x, vertices[j + 3].y, vertices[j + 5].x, vertices[j + 5].y, selector);
				/** @type {number} */
				n = -2;
				/** @type {number} */
				p = 2;
				/** @type {number} */
				e = -1;
				/** @type {number} */
				z = 3;
			} else {
				add(vertices[j + 3].x, vertices[j + 3].y, vertices[j + 5].x, vertices[j + 5].y, selector);
				if (140 < children[i]) {
					break;
				}
				add(vertices[j + 4].x, vertices[j + 4].y, vertices[j + 7].x, vertices[j + 7].y, selector);
				if (135 < children[i]) {
					break;
				}
				add(vertices[j + 6].x, vertices[j + 6].y, vertices[j + 9].x, vertices[j + 9].y, selector);
				if (130 < children[i]) {
					break;
				}
				add(vertices[j + 8].x, vertices[j + 8].y, vertices[j + 10].x, vertices[j + 10].y, selector);
				if (125 < children[i]) {
					break;
				}
				/** @type {number} */
				n = -1;
				/** @type {number} */
				p = 1;
				/** @type {number} */
				e = -1;
				/** @type {number} */
				z = 1;
			}
			start = 0 == settings[list[i]][0] ? data : settings[list[i]][0];
			if (13 == i1) {
				/** @type {number} */
				start = 0;
			}
			/** @type {number} */
			var s = e;
			for (; s <= z; s++) {
				/** @type {number} */
				var k = n;
				for (; k <= p; k++) {
					if (!(n + 1 <= k && k <= p - 1 && e + 1 <= s && s <= z - 1)) {
						var y = parseInt(vertices[j].x) + k;
						var x = parseInt(vertices[j].y) + s;
						if (!(8 > y || 408 <= y || 8 > x || 308 <= x || 1 == g_board[i] && k == n && s == e || 1 == g_board[i] && k == p && s == e || 1 == g_board[i] && k == n && s == z || 1 == g_board[i] && k == p && s == z)) {
							y = x * length + y;
							pixels[y] = pixels[y] == start ? 0 : start;
						}
					}
				}
			}
			if (11 == i1) {
				n = parseInt(clamp(vertices[j + 0].x, 8, 407));
				e = parseInt(clamp(vertices[j + 0].y, 8, 304));
				/** @type {number} */
				s = e - 4;
				for (; s <= e + 4; s = s + 4) {
					/** @type {number} */
					k = n - 4;
					for (; k <= n + 4; k = k + 4) {
						/** @type {number} */
						buffer[s * length + k] = 536870911;
					}
				}
			}
			break;
		case auto:
			/** @type {number} */
			start = 9465872;
			if (13 == i1) {
				/** @type {number} */
				start = 0;
			}
			if (keys[j] == item) {
				add(vertices[j].x, vertices[j].y, vertices[j].x, vertices[j].y + 3, start);
				add(vertices[j].x, vertices[j].y, vertices[j].x + 3, vertices[j].y, start);
				add(vertices[j].x, vertices[j].y + 2, vertices[j].x + 2, vertices[j].y + 2, start);
			} else {
				if (keys[j] == tr) {
					filter(parseInt(vertices[j].x), parseInt(vertices[j].y), 3, 3, start);
				} else {
					if (keys[j] == float) {
						add(vertices[j].x, vertices[j].y, vertices[j].x, vertices[j].y + 3, start);
						add(vertices[j].x, vertices[j].y, vertices[j].x + 2, vertices[j].y, start);
						add(vertices[j].x, vertices[j].y + 2, vertices[j].x + 2, vertices[j].y + 2, start);
						add(vertices[j].x + 3, vertices[j].y, vertices[j].x + 3, vertices[j].y + 2, start);
					} else {
						if (-2 == keys[j]) {
							add(vertices[j].x + 1, vertices[j].y, vertices[j].x + 2, vertices[j].y, start);
							add(vertices[j].x, vertices[j].y + 1, vertices[j].x, vertices[j].y + 2, start);
							add(vertices[j].x + 3, vertices[j].y + 1, vertices[j].x + 3, vertices[j].y + 2, start);
							add(vertices[j].x + 1, vertices[j].y + 3, vertices[j].x + 2, vertices[j].y + 3, start);
						} else {
							drawLine(parseInt(vertices[j].x), parseInt(vertices[j].y), 4, 4, start);
						}
					}
				}
			}
		}
		switch(rows[i]) {
		case item:
		case item + 1:
		case item + 2:
		case item + 3:
		case float:
		case float + 2:
		case float + 3:
			if (12 == i1) {
				/** @type {number} */
				start = 0;
				for (; 6 > start; start++) {
					n = parseInt(clamp(vertices[j + start].x, 8, 407));
					e = parseInt(clamp(vertices[j + start].y, 8, 304));
					/** @type {number} */
					buffer[e * length + n] = 3E3;
				}
			}
		}
	}
};
/** @type {number} */
var _len = 50;
/** @type {!Array} */
var objects = Array(_len);
/** @type {!Array} */
var nodes = Array(_len);
/** @type {!Array} */
var plugins = Array(_len);
/** @type {!Array} */
var cache = Array(_len);
/** @type {!Array} */
var states = Array(_len);
/** @type {!Array} */
var data = Array(_len);
var index;
/** @type {number} */
index = 0;
for (; index < _len; index++) {
	objects[index] = new Vector;
}
/** @type {number} */
index = 0;
for (; index < _len; index++) {
	nodes[index] = new Vector;
}
/** @type {!Array} */
var attrs = [-length - 1, -length, -length + 1, -1, 0, 1, length - 1, length, length + 1, 2 * -length - 1, 2 * -length, 2 * -length + 1, 2 * length - 1, 2 * length, 2 * length + 1, -2 - length, -2, -2 + length, 2 - length, 2, 2 + length, 3 * -length - 1, 3 * -length, 3 * -length + 1, 3 * length - 1, 3 * length, 3 * length + 1, -3 - length, -3, -3 + length, 3 - length, 3, 3 + length, -2 - 
				 2 * length, 2 - 2 * length, -2 + 2 * length, 2 + 2 * length];
/** @type {!Array} */
var dots = [-0.7, 0, 0.7, -1, 0, 1, -0.7, 0, 0.7, -0.44, 0, 0.44, -0.44, 0, 0.44, -0.89, -1, -0.89, 0.89, 1, 0.89, -0.31, 0, 0.31, -0.31, 0, 0.31, -0.94, -1, -0.94, 0.94, 1, 0.94, -0.7, 0.7, -0.7, 0.7];
/** @type {!Array} */
var v2 = [-0.7, -1, -0.7, 0, 0, 0, 0.7, 1, 0.7, -0.89, -1, -0.89, 0.89, 1, 0.89, -0.44, 0, 0.44, -0.44, 0, 0.44, -0.94, -1, -0.94, 0.94, 1, 0.94, -0.31, 0, 0.31, -0.31, 0, 0.31, -0.7, -0.7, 0.7, 0.7];
/** @type {!Array} */
var units = [-1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -2, -2, -2, 2, 2, 2, -1, 0, 1, -1, 0, 1, -3, -3, -3, 3, 3, 3, -2, 2, -2, 2];
/** @type {!Array} */
var pathsMatches = [-1, -1, -1, 0, 0, 0, 1, 1, 1, -2, -2, -2, 2, 2, 2, -1, 0, 1, -1, 0, 1, -3, -3, -3, 3, 3, 3, -1, 0, 1, -1, 0, 1, -2, -2, 2, 2];
/** @type {!Array} */
var lookup = [0, 0, 0.1, 0.1, -0.03, 0.1, 0.1, 0.1, 0.1, 0, 0.1, 0.02, 0.05, 0.1, 0.1, 0.1, 0.1, 0.1, 0, 0.1, 0.1, 0.1, 0, 0.1, 0.1, 0.1, -0.01, 0.1, 0.1, 0.2, 0, 0.1, 0, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.05, 0, 0.2, 0.1, 0.1, -0.02, 0.1];
/** @type {!Array} */
var Shares = [0, 0, 0.5, 0.4, 0.5, 0.5, 0.4, 0.4, 0.9, 0, 0.3, 0.5, 0.5, 0.3, 0.3, 0.3, 0, 0.2, 0, 0.1, 0, 0.5, 0, 0.3, 0.5, 0.3, 0.5, 0.4, 0, 0, 0, 0.1, 0, 0, 0.4, 0.4, 0.5, 0.4, 0.2, 0.5, 0, 0, 0.5, 0.2, 0.5, 0];
/** @type {!Array} */
var observed_frequencies = [0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1];
/** @type {function(): undefined} */
msg.fff = e.prototype.t;
/**
 * @return {undefined}
 */
e.prototype.t = function() {
	var i;
	var j;
	var x;
	var c = new Vector;
	/** @type {number} */
	i = 0;
	for (; i < _len; i++) {
		if (0 != plugins[i]) {
			if (0 == observed_frequencies[data[i]]) {
				/** @type {number} */
				plugins[i] = 0;
			} else {
				x = parseInt(objects[i].y) * length + parseInt(objects[i].x);
				/** @type {number} */
				j = 0;
				for (; 21 > j; j++) {
					if (-2 == obj[x + attrs[j]]) {
						/** @type {number} */
						obj[x + attrs[j]] = element;
					}
				}
				var s = lookup[data[i]];
				nodes[i].y += s;
				j = Shares[data[i]];
				if (0 != j) {
					/** @type {number} */
					x = (parseInt(objects[i].y) >> 2) * step + (parseInt(objects[i].x) >> 2);
					nodes[i].x += values[x].x * j;
					nodes[i].y += values[x].y * j;
					if (0.3 < expect(values[x])) {
						parse(nodes[i], 0.9 + (1 - j) / 10);
					}
				}
				/** @type {number} */
				x = i;
				j = new Vector;
				if (0 == states[x]) {
					if (42 == url && hasToggledVideo || 42 == l && hasToggledAudio) {
						/** @type {number} */
						j.x = value - objects[x].x;
						/** @type {number} */
						j.y = y - objects[x].y;
						if (20 > expect(j)) {
							/** @type {number} */
							states[x] = 1;
						}
					}
				} else {
					if (42 == url && target || 42 == l && cmp) {
						nodes[x].x += 0.05 * (value - objects[x].x);
						nodes[x].y += 0.05 * (y - objects[x].y);
						parse(nodes[x], 0.9);
					} else {
						parse(nodes[x], 0.3);
						/** @type {number} */
						states[x] = 0;
					}
				}
				/** @type {number} */
				j = 0;
				for (; j < to; j++) {
					if (rows[j] == item || rows[j] == item + 1 || rows[j] == float) {
						/** @type {number} */
						x = j * stride;
						/** @type {number} */
						var a = 4;
						for (; 5 >= a; a++) {
							var key = abs(vertices[x + a].y - objects[i].y);
							if (9 >= abs(vertices[x + a].x - objects[i].x) && 9 >= key) {
								nodes[i].x += 0.1 * (vertices[x + a].x - row[x + a].x);
								nodes[i].y += 0.2 * (vertices[x + a].y - row[x + a].y);
							}
						}
					}
				}
				a = new Vector;
				a.set(nodes[i]);
				/** @type {number} */
				index = 0;
				var y = parseInt(dist(nodes[i]) / 2) + 1;
				/** @type {number} */
				var k = 1 / y;
				var left;
				var height;
				/** @type {number} */
				var p = 0;
				var b = new Vector;
				/** @type {number} */
				var t = key = 0;
				for (; t < y; t++) {
					left = objects[i].x + nodes[i].x * k;
					height = objects[i].y + nodes[i].y * k;
					if (4 > left || length - 4 <= left || 4 > height || 312 <= height) {
						/** @type {number} */
						plugins[i] = 0;
						break;
					}
					if (1 == option) {
						if (8 > left) {
							if (obj[parseInt(height) * length + parseInt(left + 400)] <= temp) {
								objects[i].x += 400;
								nodes[i].x *= 0.8;
							} else {
								nodes[i].x *= -0.8;
							}
							left = objects[i].x + nodes[i].x * k;
						} else {
							if (408 <= left) {
								if (obj[parseInt(height) * length + parseInt(left - 400)] <= temp) {
									objects[i].x -= 400;
									nodes[i].x *= 0.8;
								} else {
									nodes[i].x *= -0.8;
								}
								left = objects[i].x + nodes[i].x * k;
							}
						}
						if (8 > height) {
							if (obj[parseInt(height + 300) * length + parseInt(left)] <= temp) {
								objects[i].y += 300;
								nodes[i].y *= 0.8;
							} else {
								nodes[i].y *= -0.8;
							}
							height = objects[i].y + nodes[i].y * k;
						} else {
							if (308 <= height) {
								if (obj[parseInt(height - 300) * length + parseInt(left)] <= temp) {
									objects[i].y -= 300;
									nodes[i].y *= 0.5;
								} else {
									nodes[i].y *= -0.8;
								}
								height = objects[i].y + nodes[i].y * k;
							}
						}
					}
					x = parseInt(height) * length + parseInt(left);
					/** @type {number} */
					p = 0;
					cb(b, 0, 0);
					/** @type {number} */
					j = 0;
					for (; 37 > j; j++) {
						/** @type {number} */
						var prop = obj[x + attrs[j]];
						if (!(prop <= temp)) {
							/** @type {number} */
							key = prop;
							if (0 <= prop && (key = args[prop], 1 == visit(i, key, prop))) {
								continue;
							}
							b.x -= dots[j];
							b.y -= v2[j];
							p++;
						}
					}
					if (0 == p) {
						objects[i].x = left;
						objects[i].y = height;
					} else {
						collide(b);
						nodes[i].y -= s;
						/** @type {number} */
						j = 0.999 * dist(nodes[i]);
						parse(b, -(b.x * nodes[i].x + b.y * nodes[i].y));
						nodes[i].add(b);
						parse(nodes[i], 0.999);
						parse(b, 0.1);
						nodes[i].add(b);
						collide(nodes[i]);
						parse(nodes[i], j);
						objects[i].x += nodes[i].x * k;
						objects[i].y += nodes[i].y * k;
						nodes[i].y += s;
					}
					x = parseInt(objects[i].y) * length + parseInt(objects[i].x);
					/** @type {number} */
					p = 0;
					cb(b, 0, 0);
					/** @type {number} */
					j = 0;
					for (; 21 > j; j++) {
						if (prop = obj[x + attrs[j]], !(prop <= temp)) {
							if (0 <= prop) {
								if (2 == hash[args[prop]] && 2 == hash[data[i]] && data[i] != args[prop]) {
									continue;
								}
								if (2 == hash[args[prop]] && 2 != hash[data[i]]) {
									continue;
								}
								if (5 == hash[args[prop]] && 5 != hash[data[i]]) {
									continue;
								}
								if (args[prop] == title && 2 == hash[data[i]]) {
									continue;
								}
								if (args[prop] == options) {
									continue;
								}
								if (args[prop] == end && data[i] == end) {
									continue;
								}
							}
							b.x -= dots[j];
							b.y -= v2[j];
							p++;
						}
					}
					if (0 != p) {
						collide(b);
						objects[i].add(b);
					}
				}
				if (4 > objects[i].x || length - 4 <= objects[i].x || 4 > objects[i].y || 312 <= objects[i].y) {
					/** @type {number} */
					plugins[i] = 0;
					break;
				}
				x = parseInt(objects[i].y) * length + parseInt(objects[i].x);
				/** @type {number} */
				s = 0;
				if (data[i] == _ && 0 <= key) {
					if (2 == hash[key]) {
						debug(i, x, 0, _, 0, 0.5 * nodes[i].x, 0.5 * nodes[i].y, 0.5);
					} else {
						if (3 == hash[key]) {
							debug(i, x, 0, options, 0, 0.5 * nodes[i].x, 0.5 * nodes[i].y, 0.5);
						}
					}
				} else {
					if (data[i] == name) {
						if (!(key != object && key != end && key != parent)) {
							debug(i, x, 0, name, 0, 0, 0, 0);
						}
					} else {
						if (data[i] == current) {
							j = dist(a);
							if (key == end || key == parent || (-1 == key || -3 == key || key == tag || key == val || key == host) && 5 < j) {
								debug(i, x, 0, 11, 0, a.x, a.y, j);
							}
						} else {
							if (37 == data[i]) {
								if (!(key != end && key != parent)) {
									debug(i, x, 0, 37, 0, 0, 0, 0);
								}
							} else {
								if (data[i] == size) {
									if (!(key != object && key != end && key != parent)) {
										debug(i, x, 0, size, 0, 0, 0, 0);
									}
								} else {
									if (data[i] == options) {
										if (!(key != name && key != v && 37 != key && key != parent)) {
											debug(i, x, 0, options, 0, 0, 0, 0);
										}
									}
								}
							}
						}
					}
				}
				if (data[i] == number && 0 <= key) {
					if (key == parent) {
						debug(i, x, 0, number, 0, 0.5 * nodes[i].x, 0.5 * nodes[i].y, 0.5);
					} else {
						if (key != event && 3 == hash[key]) {
							debug(i, x, 0, options, 0, 0.5 * nodes[i].x, 0.5 * nodes[i].y, 0.5);
						}
					}
				}
				if (6 == data[i] && 0 <= key) {
					if (key == elem) {
						debug(i, x, 0, elem, 0, 0, 0, 0);
					} else {
						if (key == parent) {
							debug(i, x, 0, _, 0, 0, 0, 0);
						} else {
							if (key == end) {
								debug(i, x, 0, _, 0, 0, 0, 1);
							} else {
								if (key != event) {
									if (3 == hash[key] && 1 == cache[i]) {
										debug(i, x, 0, 6, 1, 0, 0, 0);
									} else {
										if (3 == hash[key]) {
											debug(i, x, 0, options, 0, 0, 0, 0);
										}
									}
								}
							}
						}
					}
				} else {
					if (data[i] == message && 0 <= key) {
						if (3 == hash[key] && 0 == cache[i]) {
							/** @type {number} */
							j = 0;
							for (; 37 > j; j++) {
								/** @type {number} */
								prop = obj[x + attrs[j]];
								if (prop <= temp) {
									s = callback(parseInt(objects[i].x) + units[j], parseInt(objects[i].y) + pathsMatches[j], options);
									if (0 < s) {
										a = apply(20);
										items[s].x += nodes[i].x * a + dots[j] * a / 2;
										items[s].y += nodes[i].y * a + v2[j] * a / 2;
										/** @type {number} */
										arr[s] = 2;
									}
								}
							}
							/** @type {number} */
							plugins[i] = 0;
						} else {
							if (key == parent) {
								debug(i, x, 0, message, 0, 0, 0, 0);
							}
						}
					} else {
						if (data[i] == r && 0 <= key) {
							if (3 == hash[key]) {
								/** @type {number} */
								j = 9;
								for (; 21 > j; j++) {
									/** @type {number} */
									prop = obj[x + attrs[j]];
									if (prop <= temp && 50 > apply(100)) {
										callback(parseInt(objects[i].x) + units[j], parseInt(objects[i].y) + pathsMatches[j], options);
									}
								}
								if (1 > apply(100)) {
									debug(i, x, 0, r, 0, 0, 0, 0);
								}
							} else {
								if (key == parent) {
									debug(i, x, 0, r, 0, 0, 0, 0);
								}
							}
						} else {
							if (data[i] == v) {
								if (!(key != object && key != end && key != parent)) {
									debug(i, x, 0, v, 0, 0, 0, 0);
								}
							} else {
								if (data[i] == id && 0 < key) {
									/** @type {number} */
									x = (parseInt(objects[i].y) >> 2) * step + (parseInt(objects[i].x) >> 2);
									buf[x] += 10;
									/** @type {number} */
									t = t - 10;
								} else {
									if (data[i] == string) {
										if (0 == cache[i] && 0 < key) {
											/** @type {number} */
											cache[i] = key;
										} else {
											if (0 != cache[i] && !(1E3 > beginHint[max] - k)) {
												s = parseInt(objects[i].x);
												x = parseInt(objects[i].y);
												if (1 == hash[cache[i]] || cache[i] == object || cache[i] == event) {
													x = x + 4;
												}
												j = x * length + s;
												if (obj[j] <= temp) {
													callback(s, x, cache[i]);
												}
											}
										}
									} else {
										if ((data[i] == command || data[i] == code) && 0 <= key) {
											if (3 == hash[key]) {
												/** @type {number} */
												a = 10;
												/** @type {number} */
												key = parseInt(objects[i].x) & 65532;
												/** @type {number} */
												y = parseInt(objects[i].y) & 65532;
												k = max(key - a, width);
												b = max(y - a, width);
												t = min(key + a, length - width - 1);
												left = min(y + a, (cols - 1) * width - 1);
												x = b;
												for (; x <= left; x++) {
													s = k;
													for (; s <= t; s++) {
														if (!((s - key) * (s - key) + (x - y) * (x - y) > a * a)) {
															j = x * length + s;
															if (0 <= obj[j]) {
																items[obj[j]].x += 10 * (s - key);
																items[obj[j]].y += 10 * (x - y);
															}
															if (obj[j] <= temp && data[i] == code) {
																callback(s, x, options);
															}
															if (0 == (x & 3) + (s & 3)) {
																/** @type {number} */
																j = (x >> 2) * step + (s >> 2);
																if (0 >= out[j]) {
																	if (1 <= abs(s - key)) {
																		values[j].x += 100 / (s - key);
																	}
																	if (1 <= abs(x - y)) {
																		values[j].y += 100 / (x - y);
																	}
																}
															}
														}
													}
												}
												/** @type {number} */
												plugins[i] = 0;
											} else {
												if (key == parent) {
													debug(i, x, 0, data[i], 0, 0, 0, 0);
												}
											}
										} else {
											if (data[i] == date && 0 <= key) {
												if (3 == hash[key]) {
													debug(i, x, 0, data[i], 0, 0, 0, 1);
													if (2 > cache[i]) {
														cache[i]++;
														/** @type {number} */
														plugins[i] = 1;
													}
												} else {
													if (key == parent) {
														debug(i, x, 0, data[i], 0, 0, 0, 0);
													}
												}
											} else {
												if (data[i] == n && 0 <= key) {
													if (0 < hash[key]) {
														debug(i, x, 0, key, 0, 0.5 * nodes[i].x, 0.5 * nodes[i].y, 0.5);
													}
												} else {
													if (data[i] == host && 0 <= key) {
														if (key != host && key != options && key != date && key != title && 0 < hash[key]) {
															/** @type {number} */
															a = 10;
															key = parseInt(objects[i].x);
															y = parseInt(objects[i].y);
															k = max(key - a, width);
															b = max(y - a, width);
															t = min(key + a, length - width - 1);
															left = min(y + a, (cols - 1) * width - 1);
															cb(c, 0, 0);
															x = b;
															for (; x <= left; x++) {
																s = k;
																for (; s <= t; s++) {
																	if (!((s - key) * (s - key) + (x - y) * (x - y) > a * a)) {
																		j = x * length + s;
																		if (0 <= obj[j]) {
																			c.x += objects[i].x - s;
																			c.y += objects[i].y - x;
																		}
																	}
																}
															}
															get(c);
															x = b;
															for (; x <= left; x++) {
																s = k;
																for (; s <= t; s++) {
																	if (!((s - key) * (s - key) + (x - y) * (x - y) > a * a)) {
																		j = x * length + s;
																		if (0 <= obj[j]) {
																			/** @type {number} */
																			arr[obj[j]] = args[obj[j]];
																			/** @type {number} */
																			args[obj[j]] = host;
																			/** @type {number} */
																			map[obj[j]] = 0;
																			items[obj[j]].x += 0.5 * c.x + 0.5 * (key - s);
																			items[obj[j]].y += 0.5 * c.y + 0.5 * (y - x);
																		}
																	}
																}
															}
															/** @type {number} */
															plugins[i] = 0;
														}
													} else {
														if (data[i] == node && 0 <= key) {
															if (3 == hash[key]) {
																debug(i, x, 0, options, 0, 0.5 * nodes[i].x, 0.5 * nodes[i].y, 0.5);
															} else {
																if (key == parent) {
																	debug(i, x, 0, node, 0, 0, 0, 0);
																}
															}
														} else {
															if (data[i] == tag) {
																j = dist(a);
																if ((-1 == key || key == val || key == host) && 7 < j) {
																	/** @type {number} */
																	data[i] = _;
																} else {
																	if (key == parent) {
																		debug(i, x, 0, tag, 0, 0, 0, 0);
																	}
																}
															} else {
																if (data[i] == val) {
																	if (37 == key) {
																		debug(i, x, 1, _, 0, 0, 0, 0);
																	} else {
																		if (key == end) {
																			debug(i, x, 2, val, 0, 0, 0, 0);
																		} else {
																			if (key == title) {
																				debug(i, x, 1, val, 0, 0, 0, 0);
																			} else {
																				if (key == parent) {
																					debug(i, x, 0, val, 0, 0, 0, 0);
																				}
																			}
																		}
																	}
																} else {
																	if (data[i] == key) {
																		j = dist(a);
																		if ((-1 == key || -3 == key || key == tag || key == val || key == host) && 5 < j) {
																			debug(i, x, 0, tag, 0, 0, 0, 0.1 * j);
																		} else {
																			if (key == end) {
																				debug(i, x, 1, key, 0, 0, 0, 0);
																			} else {
																				if (key == title) {
																					debug(i, x, 2, key, 0, 0, 0, 0);
																				} else {
																					if (key == parent) {
																						debug(i, x, 0, key, 0, 0, 0, 0);
																					}
																				}
																			}
																		}
																	} else {
																		if (data[i] == elem) {
																			if (key == name) {
																				debug(i, x, 0, elem, 0, 0, 0, 0);
																			} else {
																				if (key == v) {
																					debug(i, x, 0, elem, 0, 0, 0, 0);
																				} else {
																					if (37 == key) {
																						debug(i, x, 0, elem, 0, 0, 0, 0);
																					} else {
																						if (key == end) {
																							debug(i, x, 0, options, 0, 0, 0, 0);
																						} else {
																							if (key == parent) {
																								debug(i, x, 0, elem, 0, 0, 0, 0);
																							}
																						}
																					}
																				}
																			}
																		} else {
																			if (data[i] == action && 0 <= key) {
																				if (3 == hash[key]) {
																					if (cache[i] == r) {
																						debug(i, x, 2, options, 0, 0, 0, 0);
																					} else {
																						if (cache[i] == code) {
																							debug(i, x, 0, code, 0, 0, 0, 1);
																						} else {
																							if (cache[i] == v) {
																								debug(i, x, 0, n, 0, 0, 0, 1);
																							} else {
																								debug(i, x, 0, event, 0, 0, 0, 0);
																							}
																						}
																					}
																				} else {
																					if (key == name) {
																						debug(i, x, 0, message, 0, 0, 0, 0);
																					} else {
																						if (37 == key) {
																							debug(i, x, 0, message, 0, 0, 0, 0);
																						} else {
																							if (key == parent) {
																								debug(i, x, 0, action, 0, 0, 0, 0);
																							}
																						}
																					}
																				}
																			} else {
																				if (data[i] == h) {
																					if (key == parent) {
																						debug(i, x, 0, h, 0, 0, 0, 0);
																					}
																				} else {
																					if (!(data[i] != none || 0 == cache[i] || 1E3 > beginHint[max] - k)) {
																						c.set(nodes[i]);
																						get(c);
																						parse(c, 4);
																						s = parseInt(objects[i].x - c.x);
																						x = parseInt(objects[i].y - c.y);
																						j = x * length + s;
																						if (obj[j] <= temp) {
																							/** @type {number} */
																							j = cache[i] & 255;
																							/** @type {number} */
																							a = cache[i] >> 8;
																							if (0 < a) {
																								callback(s, x, j);
																								/** @type {number} */
																								cache[i] = a - 1 << 8 | j;
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (0 != index) {
					/** @type {number} */
					data[i] = index;
					/** @type {number} */
					cache[i] = 0;
				}
				if (0 != plugins[i]) {
					x = parseInt(objects[i].y) * length + parseInt(objects[i].x);
					/** @type {number} */
					j = 0;
					for (; 21 > j; j++) {
						if (obj[x + attrs[j]] <= temp) {
							/** @type {number} */
							obj[x + attrs[j]] = -2;
						}
					}
				}
			}
		}
	}
};
/** @type {function(): undefined} */
msg.fff = e.prototype.s;
/**
 * @return {undefined}
 */
e.prototype.s = function() {
	var i;
	var j;
	var x;
	var value;
	/** @type {number} */
	i = 0;
	for (; i < _len; i++) {
		if (0 != plugins[i]) {
			x = parseInt(objects[i].y) * length + parseInt(objects[i].x);
			value = settings[data[i]][0];
			if (13 == i1) {
				/** @type {number} */
				value = 0;
			}
			/** @type {number} */
			j = 9;
			for (; 21 > j; j++) {
				pixels[x + attrs[j]] = value;
			}
			if (308 > objects[i].y) {
				if (11 == i1) {
					if (data[i] == options || data[i] == object || data[i] == elem || data[i] == end || data[i] == title || data[i] == event) {
						/** @type {number} */
						buffer[x] = 255E3;
					}
				} else {
					if (12 == i1) {
						/** @type {number} */
						buffer[x] = 2 * cell[data[i]];
					}
				}
			}
		}
	}
};
/** @type {!HTMLDocument} */
var el = document;
/** @type {(Element|null)} */
var canvas = el.getElementById("cv");
var ctx = canvas.getContext("2d");
var opts = ctx.createImageData(length, height);
/** @type {!Uint8Array} */
var tex = new Uint8Array(opts.data.buffer);
/** @type {!Console} */
var cc = msg.console;
/** @type {function(...number): string} */
var $ = String.fromCharCode;
/** @type {function((!Function|null|string), number=, ...*): number} */
var emit = setTimeout;
/** @type {string} */
var dump1 = "dan-ball.jp";
/** @type {function(number, number, string, number, number, number, number): undefined} */
msg.fff = text;
/** @type {function(number): undefined} */
msg.fff = fill;
/** @type {function(number, number, number): undefined} */
msg.Init = create;
/** @type {string} */
var points = $(68, 65, 78, 45, 66, 65, 76, 76, 46, 106, 112, 32, 40, 67, 41, 32, 50, 48, 48, 55, 32, 104, 97, 53, 53, 105, 105);
/** @type {string} */
var imageModelSection = $(46, 47, 100, 97, 116, 97, 47);
/** @type {string} */
var fileName = $(102, 112, 115);
/** @type {string} */
var wrapper = $(99, 97, 110, 118, 97, 115);
/** @type {string} */
var origin = $(50, 100);
/** @type {number} */
var i = 0;
/** @type {string} */
var dump2 = $(100, 97, 110, 45, 98, 97, 108, 108, 46, 106, 112);
/** @type {!Int32Array} */
var pixels = new Int32Array(length * height);
/** @type {function(): undefined} */
msg.fff = drawPlayButton;
/** @type {number} */
var Pb = 1;
var callGlobalHandler = window.requestAnimationFrame || window.mozRequestAnimationFrame || window.webkitRequestAnimationFrame || window.oRequestAnimationFrame || window.msRequestAnimationFrame;
/** @type {number} */
var Ef = 0;
/** @type {number} */
var minx = 0;
/** @type {number} */
var idOrPath = 0;
/** @type {number} */
var path = 0;
/** @type {number} */
var _Position_OuterEnd = 0;
/** @type {number} */
var level = 0;
/** @type {number} */
var offsetX = 20;
/** @type {number} */
var mouseX = Date.now();
var lastMouseX = mouseX;
var startX = mouseX + offsetX;
var oldmouseX = mouseX;
/** @type {number} */
var Rf = 0;
/** @type {number} */
var Cb = 0;
/**
 * @param {number} id
 * @return {undefined}
 */
Matrix.prototype.e = function(id) {
	if (this.file != id) {
		Cb++;
		/** @type {number} */
		this.file = id;
		/** @type {!Image} */
		this.d = new Image;
		/** @type {string} */
		this.d.src = imageModelSection + id + "?9.2";
		delete this.b;
		/** @type {number} */
		this.k = this.b = 0;
	}
};
/** @type {!Array} */
var directMandates = [[0, 2, 0, 0, 1, 0, 0, 2, 2, 1, 1, 1, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 3, 1, 0], [0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 
																																																																																																							 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0]];
/** @type {!Array} */
var eprops = [[0, 1, 1, 0, 0, 0, 0, 2, 1, 2, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0], [0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 
																																																																																																				  1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0]];
var self = new clone;
/**
 * @param {?} err
 * @param {number} n
 * @param {number} v
 * @return {undefined}
 */
clone.prototype.e = function(err, n, v) {
	this.o.e(err);
	/** @type {number} */
	this.h = n;
	/** @type {number} */
	this.p = v;
	/** @type {number} */
	this.j = this.m = 0;
};
/**
 * @param {number} x
 * @param {number} size
 * @param {string} type
 * @param {number} c
 * @param {number} r
 * @return {undefined}
 */
clone.prototype.a = function(x, size, type, c, r) {
	var j;
	var d;
	var i2;
	var index;
	var p;
	var i;
	var period;
	/** @type {number} */
	var delta = length - this.h;
	/** @type {number} */
	var GROUPSIZE = this.o.c - this.h;
	/** @type {number} */
	var Y = -1 < c ? 16777215 : 1;
	/** @type {number} */
	var D = -1 < r ? 0 : 1;
	var len = type.length;
	/** @type {number} */
	j = 0;
	for (; j < len; j++, x = x + (this.h + this.m)) {
		if (p = type.charCodeAt(j) - 32, 0 != p) {
			if (96 <= p) {
				/** @type {number} */
				p = 31;
			}
			if (0 != this.j) {
				/** @type {number} */
				x = x - directMandates[this.j - 1][p];
			}
			/** @type {number} */
			i = p * this.h;
			index = size * length + x;
			/** @type {number} */
			i2 = 0;
			for (; i2 < this.p; i2++, index = index + delta, i = i + GROUPSIZE) {
				/** @type {number} */
				d = 0;
				for (; d < this.h; d++, index++, i++) {
					period = this.o.b[i];
					if (period == Y) {
						/** @type {number} */
						pixels[index] = c;
					} else {
						if (period == D) {
							/** @type {number} */
							pixels[index] = r;
						}
					}
				}
			}
			if (0 != this.j) {
				/** @type {number} */
				x = x - eprops[this.j - 1][p];
			}
		}
	}
	/** @type {number} */
	this.j = 0;
};
/** @type {number} */
var div = 0;
/** @type {number} */
var Yf = 0;
var scale = new Vector;
/** @type {boolean} */
var hasToggledVideo = false;
/** @type {boolean} */
var rx = false;
/** @type {boolean} */
var target = false;
/** @type {boolean} */
var source = false;
/** @type {boolean} */
var hasToggledAudio = false;
/** @type {boolean} */
var ry = false;
/** @type {boolean} */
var cmp = false;
/** @type {boolean} */
var cursorTrack = false;
/** @type {boolean} */
var historyInstance = false;
/** @type {number} */
var dx = 0;
/** @type {number} */
var lat = 0;
/** @type {number} */
var lon = 0;
/** @type {number} */
var lastLat = 0;
/** @type {number} */
var lastLon = 0;
/** @type {number} */
var version = 0;
/** @type {number} */
var py = 0;
/** @type {function(!Event): undefined} */
el.onmousemove = _getColorCanvas;
/**
 * @param {!Event} event
 * @return {?}
 */
el.onmousedown = function(event) {
	_getColorCanvas(event);
	/** @type {boolean} */
	_next = false;
	if (!(0 > version || length <= version || 0 > py || height <= py) && (_next = true, 0 == event.button && (source = true), 2 == event.button && (cursorTrack = true), _next)) {
		return false;
	}
};
/**
 * @param {!Event} event
 * @return {undefined}
 */
el.onmouseup = function(event) {
	_getColorCanvas(event);
	if (0 == event.button) {
		/** @type {boolean} */
		source = false;
	}
	if (2 == event.button) {
		/** @type {boolean} */
		cursorTrack = false;
	}
};
/**
 * @return {?}
 */
el.oncontextmenu = function() {
	if (_next) {
		return false;
	}
};
/**
 * @param {!Object} e
 * @return {?}
 */
canvas.ontouchstart = function(e) {
	drag(e);
	/** @type {boolean} */
	source = true;
	if (1 < e.touches.length) {
		/** @type {boolean} */
		cursorTrack = true;
	}
	return false;
};
/**
 * @param {!Object} e
 * @return {?}
 */
canvas.ontouchmove = function(e) {
	drag(e);
	return false;
};
/**
 * @param {!Event} event
 * @return {?}
 */
canvas.ontouchend = function(event) {
	if (1 > event.touches.length) {
		/** @type {boolean} */
		source = false;
	}
	return cursorTrack = false;
};
/**
 * @return {undefined}
 */
canvas.ontouchcancel = function() {
	/** @type {boolean} */
	cursorTrack = source = false;
};
/** @type {!Array} */
var box = Array(256);
/** @type {!Array} */
var patches = Array(256);
/** @type {!Array} */
var pairs = Array(256);
/** @type {!Array} */
var files = Array(256);
/** @type {!Array} */
var body = Array(256);
/**
 * @param {!Event} options
 * @return {?}
 */
el.onkeydown = function(options) {
	var i = options.keyCode;
	if (65 <= i & 90 >= i) {
		if (!options.shiftKey) {
			i = i + 32;
		}
	} else {
		i = options.shiftKey ? body[i] : files[i];
	}
	if (0 <= i && 256 > i) {
		/** @type {boolean} */
		pairs[i] = true;
		/** @type {boolean} */
		patches[i] = true;
	}
	if (0 != i && _next) {
		return false;
	}
};
/**
 * @param {!Event} options
 * @return {?}
 */
el.onkeyup = function(options) {
	var i = options.keyCode;
	if (65 <= i & 90 >= i) {
		if (!options.shiftKey) {
			i = i + 32;
		}
	} else {
		i = options.shiftKey ? body[i] : files[i];
	}
	if (0 <= i && 256 > i) {
		/** @type {boolean} */
		pairs[i] = false;
	}
	if (0 != i && _next) {
		return false;
	}
};
/** @type {boolean} */
var _next = false;
/** @type {!Array} */
var markup_classes = Array(100);
/** @type {number} */
var Hb = 0;
/** @type {string} */
var copy = $(80, 79, 83, 84);
/** @type {string} */
var QUERY_PREFIX = $(38, 98, 61);
/** @type {string} */
var start = $(38, 99, 61);
$(38, 100, 61);
/** @type {string} */
var tab = $(38, 101, 61);
/** @type {string} */
var advice = $(38, 102, 61);
/** @type {string} */
var tiles = $(38, 103, 61);
$(38, 104, 61);
$(38, 105, 61);
$(38, 106, 61);
$(38, 107, 61);
$(111, 107);
/** @type {string} */
var $gBCRBottom = $(69, 82, 82, 79, 82);
/** @type {string} */
var footer = $(61);
/** @type {string} */
var span = $(10);
/** @type {string} */
var header = $(67, 111, 110, 116, 101, 110, 116, 45, 84, 121, 112, 101);
/** @type {string} */
var token = $(97, 112, 112, 108, 105, 99, 97, 116, 105, 111, 110, 47, 120, 45, 119, 119, 119, 45, 102, 111, 114, 109, 45, 117, 114, 108, 101, 110, 99, 111, 100, 101, 100);
/**
 * @param {!Object} step
 * @return {?}
 */
Vector.prototype.set = function(step) {
	this.x = step.x;
	this.y = step.y;
	return this;
};
/**
 * @param {!Object} v
 * @return {?}
 */
Vector.prototype.add = function(v) {
	this.x += v.x;
	this.y += v.y;
	return this;
};
/**
 * @param {!Object} x
 * @return {?}
 */
Vector.prototype.sub = function(x) {
	this.x -= x.x;
	this.y -= x.y;
	return this;
};
/** @type {!Float32Array} */
var positions = new Float32Array(1024);
/** @type {number} */
var aL = 0;
/** @type {number} */
var bL = 0;
/** @type {!Array} */
var grid = Array(513);
/** @type {number} */
var ratio = 3.1415927;
/** @type {number} */
var firstX = 6.2831855;
