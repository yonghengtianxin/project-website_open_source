
/*
window.onload = function () {
    setTimeout(setInterval("toggleSound()", 1),1000);
}

function setInterval() {
    var music = document.getElementById("music");//��ȡID
    if (music.paused) { //�ж��Ƿ񲥷�  
        music.paused = false;
        music.play(); //û�оͲ��� 
    }
}


function play(src, type) {
	document.getElementById("audioPay").innerHTML = "<embed id='embVoice' name='embed_" + type + "' src='" + src + "' autostart=true  hidden=true muted='muted'></embed>"
	var interTimePay = setInterval(function () {
		try {
			var embedVoice = document.getElementById('embVoice');
			if (!embedVoice) {
				document.getElementById("audioPay").innerHTML = "<embed id='embVoice' name='embed_" + type + "' src='" + src + "' autostart=true  hidden=true muted='muted'></embed>"
			}
			setTimeout(function () {
				document.getElementById("embVoice").innerHTML = ""
			}, 9000)
		} catch (e) {
			console.log("�������������쳣��", e);
		}
	}, 10000);
}
var src = "/audio/ZUN - �������h�ݤʥ��������� (Live ver) ~ Egoistic Flowers.mp3";
var type = "type";
play()
*/