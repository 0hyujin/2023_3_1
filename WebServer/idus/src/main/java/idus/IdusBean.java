package idus;

public class IdusBean {
   private String username;
    private String email;
    private String password;
    private String phone;
    
    // ������, getter, setter ����
    
    // ���� getter�� setter �޼���
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
      return phone; //int Ÿ���� �ƴ�����: ��ȭ��ȣ�� 0���� �����ϴµ� int�� �ϸ� 0�� ������.
   }

   public void setPhone(String phone) {
      this.phone = phone;
   }
    
}