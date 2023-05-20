package idus;

public class IdusBean {
   private String username;
    private String email;
    private String password;
    private String phone;
    
    // 생성자, getter, setter 생략
    
    // 이하 getter와 setter 메서드
    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

   public String getPhone() {
      return phone; //int 타입이 아닌이유: 전화번호는 0으로 시작하는데 int로 하면 0이 없어짐.
   }

   public void setPhone(String phone) {
      this.phone = phone;
   }
    
}