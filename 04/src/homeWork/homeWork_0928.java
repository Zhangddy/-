package homeWork;

public class homeWork_0928 {

	public static void main(String[] args) {
		Human human = new Human("小张", "610303199911013010", "男", 190.1, 78.0);
		human.eating();
		human.sleeping();
		System.out.println(human.getNo());
		human.getInfo();
	}
	
}

class Human {
	
	private String name;
	private String no;
	private String sex;
	private double height;
	private double weight;
	
	public Human (String name, String no, String sex, double height, double weight) {
		this.name = name;
		this.sex = sex;
		this.no = setNo(no);
		this.height = height;
		this.weight = weight;
	}
	public void getInfo() {
		String s;
		if (no.charAt(16) % 2 == 1) {
			s = "男";
		} else {
			s = "女";
		}
		System.out.println("此人是" + no.substring(6, 10) 
					+ "年" + no.substring(10, 12) + "月" + no.substring(12, 14) + "日出生,是" + s +"性");
	}
	
	public void eating() {
		System.out.println(name + "在吃饭.");
	}
	public void sleeping() {
		System.out.println(name + "在睡觉.");
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getNo() {
		return no;
	}
	
	public String setNo(String no) {
		if (checkNo(no, sex)) {
			this.no = no;
		} else {
			this.no = "NUll";
		}
		return this.no;
	}
	
	public boolean checkNo(String no, String sex) {
		
		boolean status = true; 
		
		if (no.length() != 18) {
			System.out.println("证件号码长度不符合规定!");
			status = false;
		}
		int i;
		for (i = 0; i < no.length() - 1; ++i) {
			if (no.charAt(i) > '9' || no.charAt(i) < '0') {
				System.out.println("证件号码中包含非法字符, 请输入阿拉伯数字!");
				status = false;
			}
		}
		
		if ((no.charAt(16) % 2) == 1 ) {
			if (!sex.equals("男")) {
				System.out.println("证件号码性别与输入性别不同!");
				status = false;
			}
		} else {
			if (!sex.equals("女")) {
				System.out.println("证件号码性别与输入性别不同!");
				status = false;
			}
		}
		return status;
	}
	
	public String getSex() {
		return sex;
	}
	public void setSex(String sex) {
		this.sex = sex;
	}
	public double getHeight() {
		return height;
	}
	public void setHeight(double height) {
		this.height = height;
	}
	public double getWeight() {
		return weight;
	}
	public void setWeight(double weight) {
		this.weight = weight;
	}
}
