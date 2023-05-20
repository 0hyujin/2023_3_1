<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>회원 가입</title>
    <style>
        .container {
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
        }
        #signup {
        	color : orange;
        }
        .easy-signup {
        	text-align: center;
        	font-size: 5px;
        }
    </style>
    
</head>
<body>
<form action="signup_complete.jsp" method="post">
	<div class="container">
        <div class="form">
		    <!-- <h1>회원 가입</h1> -->
		    <center><img src="./images/idus.png" style="width:25%;"></center><br>
		    <hr>
		    <div class="easy-signup">정말 간단한 회원가입하기</div><br><br>
		    
		        <label for="email">이메일</label><br>
		        <input type="email" id="email" name="email" style="width:100%; padding:2% 0; border:1px solid gray; border-radius: 5px;" required><br><br>
		        
		        <label for="password">비밀번호</label><br>
		        <input type="password" id="password" name="password" style="width:100%; padding:2% 0; border:1px solid gray; border-radius: 5px;" required><br><br>
		        
		        <label for="username">닉네임</label><br>
		        <input type="text" id="username" name="username" style="width:100%; padding:2% 0; border:1px solid gray; border-radius: 5px;" required><br><br>
		        
		        <label for="phone">전화번호</label><br>
		        <input type="tel" id="phone" name="phone" oninput="this.value = this.value.replace(/[^0-9]/g, '')" style="width:100%; padding:2% 0; border:1px solid gray; border-radius: 5px;" required><br><br>
		        
		        <input type="checkbox" id="checkall">
			    <label for="all">모두 동의합니다.</label><br>
		        <hr>
		        <input type="checkbox" class="checkbox">
			    <label for="age">만 14세 이상입니다.</label><br>
			      
			    <input type="checkbox" class="checkbox">
			    <label for="use">이용약관 동의</label><br>
			      
			    <input type="checkbox" class="checkbox">
			    <label for="ok">개인정보 수집 및 이용 동의</label><br>
			      
			    <input type="checkbox" class="checkbox">
			    <label for="event">할인쿠폰/이벤트/감동적인 뉴스레터 선택 동의 (선택)</label><br><br>
		        
		        <input type="submit" id="signup" style="width:100%; padding:2% 0; border: 2px solid orange;
            background-color: white; border-radius: 5px;" value="회원가입하기">
		    
	    </div>
	</div>
	</form>
	<script>
        // 전체 선택 체크박스 요소를 가져옴
        const checkall = document.getElementById("checkall");

        // 체크박스들의 클래스로 요소들을 가져옴
        const checkboxes = document.getElementsByClassName("checkbox");

        // 전체 선택 체크박스의 상태 변경 시 이벤트 처리
        checkall.addEventListener("change", function() {
            // 전체 선택 체크박스의 상태에 따라 체크박스들의 상태 변경
            for (let i = 0; i < checkboxes.length; i++) {
                checkboxes[i].checked = checkall.checked;
            }
        });
    </script>
</body>
</html>