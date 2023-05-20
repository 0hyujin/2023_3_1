<%@ page import="idus.IdusBean" %>
<%@ page contentType="text/html; charset=utf-8" language="java" %>

<jsp:useBean id="idus" class="idus.IdusBean" scope="request" />

<%
    // 폼 데이터 수신
    String username = request.getParameter("username");
    String email = request.getParameter("email");
    String password = request.getParameter("password");
    String phone = request.getParameter("phone");
   
    // IdusBean 객체 생성 및 데이터 설정
    //IdusBean idus = new IdusBean();
    idus.setUsername(username);
    idus.setEmail(email);
    idus.setPassword(password);
    idus.setPhone(phone);

    // 가입 완료 메시지 출력을 위한 객체에 데이터 저장
    request.setAttribute("username", username);
    request.setAttribute("email", email);
    request.setAttribute("password", password);
    request.setAttribute("phone", phone);
%>
<!DOCTYPE html>
<html>
<head>
    <title>회원 가입 결과</title>
    <style>
        .container {
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
        }
    </style>
</head>
<body>
	<div class="container">
        <div class="result">
		    <h1>회원 가입 결과</h1>
		    <p>회원 가입이 성공적으로 완료되었습니다.</p>
		    <p>가입한 닉네임: <%= username %></p>
		    <p>가입한 이메일: <%= email %></p>
		    <p>가입한 비밀번호: <jsp:getProperty name="idus" property="password" /></p>
		    <p>가입한 전화번호: <jsp:getProperty name="idus" property="phone" /></p>
		</div>
	</div>
</body>
</html>