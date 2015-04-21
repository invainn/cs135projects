var canvas = document.getElementById("map");
var ctx = canvas.getContext("2d");

var score1 = new score();

ctx.fillStyle = "black";
ctx.font = "16px Arial";

ctx.fillText("Score: " + score, 320, 230);

var paused = false;

var time1 = new timex();
var time2 = new timex();
var time3 = new timex();

function timex() {
	this.time = 0;
}

function score() {
	this.score = 0;
}

var base = new baseImage();

var speedy1 = new speedy();
var speedy2 = new speedy();
var speedy3 = new speedy();

speedy1.direction = -1;
speedy3.direction = -1;

speedy1.y = 10;
speedy2.y = 60;
speedy3.y = 110;

var bubble1 = new bubbles(base.y);
var bubble2 = new bubbles(base.y);
var bubble3 = new bubbles(base.y);

function intersectRect(r1, r2) {
	return !(r2.left > r1.right ||
			 r2.right < r1.left ||
			 r2.top > r1.bottom ||
			 r2.bottom < r1.top);
}

function baseImage() {

	this.img = new Image();
	this.img.src = "assets/base.png";
	this.img.addEventListener("load", drawImage);

	this.x = 320;
	this.y = 430;
	
	this.speed = 2;
	this.direction = 1;
	
	this.draw = function() {
		ctx.drawImage(this.img, this.x, this.y);
	}
	
	this.hitWall = function() {
		if (base.x > canvas.width - this.img.width || this.x < 0) {
			base.direction = -base.direction;
		}
	}
}

function speedy() {

	this.img = new Image();
	this.img.src = "assets/speedy.png";
	this.img.addEventListener("load", drawImage);
	
	this.x = 320;
	this.y = 0;

	this.top = this.y;
	this.bottom = this.y + this.img.height;
	this.right = this.x + this.img.width;
	this.left = this.x;

	this.direction = 1;
	this.speed = (Math.random() * 3) * this.direction;
	
	this.draw = function(obj, r1, r2, r3, time, score) {
		if(intersectRect(r1, obj)|| intersectRect(r2, obj)|| intersectRect(r3, obj)) {
			console.log("intersected!");
			time.time = 300;
			score.score += 100;
			this.update();
		} else {
			this.update();
			if(time.time == 0) {
				ctx.drawImage(this.img, this.x, this.y);
			}
		}
	}
	
	this.hitWall = function() {
		if (this.x > canvas.width - this.img.width || this.x < 0) {
			this.direction = -this.direction;
		}
	}
	
	this.move = function() {
		this.speed = (Math.random() * 3) * this.direction;
		this.x += this.speed;
	}
	
	this.update = function() {
		this.top = this.y;
		this.bottom = this.y + this.img.height;
		this.right = this.x + this.img.width;
		this.left = this.x;
	}

	this.skitter = function() {
		if(Math.random() < 0.02) {
			this.direction = -this.direction;
		}
	}
}

function bubbles(basey) {
	
	this.img = new Image();
	this.img.src = "assets/bubbleSmall.png";
	this.img.addEventListener("load", drawImage);
	
	this.x = 0;
	this.y = basey;
	
	this.top = this.y;
	this.bottom = this.y + this.img.height;
	this.right = this.x + this.img.width;
	this.left = this.x;
	
	this.speed = 0;
	this.shot = false;
	
	this.draw = function() {
		ctx.drawImage(this.img, this.x, this.y);
	}
	
	this.move = function() {
		this.y -= this.speed;
	}
	
	this.shoot = function(base, obj, r1, r2, r3) {
		if(this.shot == true) {
			if(this.y > canvas.length - this.img.length || this.y < 0 || intersectRect(r1, obj) || intersectRect(r2, obj) || intersectRect(r3, obj)) {
				this.x = 0;
				this.speed = 0;
				this.y = base;
				this.shot = false;
				this.update();
			} else {
				this.update();
				this.draw();
			}
		}	
	}
	
	this.update = function() {
		this.top = this.y;
		this.bottom = this.y + this.img.height;
		this.right = this.x + this.img.width;
		this.left = this.x;
	}
}

function drawImage() {
	setInterval(update, 1000/30.0);
}

function update() {
	if(!paused) {
		ctx.clearRect(0, 0, canvas.width, canvas.height);

		base.draw();

		speedy1.skitter();
		speedy2.skitter();
		speedy3.skitter();
		
		speedy1.draw(speedy1, bubble1, bubble2, bubble3, time1, score1);
		speedy2.draw(speedy2, bubble1, bubble2, bubble3, time2, score1);
		speedy3.draw(speedy3, bubble1, bubble2, bubble3, time3, score1);
		
		bubble1.shoot(base.y, bubble1, speedy1, speedy2, speedy3);
		bubble2.shoot(base.y, bubble2, speedy1, speedy2, speedy3);
		bubble3.shoot(base.y, bubble3, speedy1, speedy2, speedy3);
		
		bubble1.move();
		bubble2.move();
		bubble3.move();
	
		// moves left and right automatically
		base.x += base.speed * base.direction;
	
		speedy1.move();
		speedy2.move();
		speedy3.move();
	
		base.hitWall();
		
		speedy1.hitWall();
		speedy2.hitWall();
		speedy3.hitWall();
		
		if(time1.time > 0) {
			time1.time--;
		}
		
		if(time2.time > 0) {
			time2.time--;
		}
		
		if(time3.time > 0) {
			time3.time--;
		}
		
		ctx.fillText("Score: " + score1.score, 520, 20);
		
		console.log(time1.time);
		
		console.log(speedy1.img.width);
		console.log(speedy1.img.height);
	} else {
		ctx.fillText("Paused", 290, 240);
	}
}

document.body.onkeydown = function(e) {
	if(e.keyCode == 39) {
		if(base.direction < 0) {
			base.direction = -base.direction;
		}
	}
	if(e.keyCode == 37) {
		if(base.direction > 0) {
			base.direction = -base.direction;
		}
	}
	if(e.keyCode == 32) {
		if(bubble1.shot == false) {
			bubble1.x = base.x;
			bubble1.speed = 2;
			bubble1.shot = true;
		} else if(bubble2.shot == false) {
			bubble2.x = base.x;
			bubble2.speed = 2;
			bubble2.shot = true;
		} else if(bubble3.shot == false) {
			bubble3.x = base.x;
			bubble3.speed = 2;
			bubble3.shot = true;
		} 
		update();
	}
	if(e.keyCode == 27) {
		if(paused == false) {
			paused = true;
		} else {
			paused = false;
		}
		update();
	}
} 

console.log("all done");