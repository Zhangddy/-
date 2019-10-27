package homeWork;

public class homeWork_0928 {

	public static void main(String[] args) {
		Human human = new Human("С��", "610303199911013010", "��", 190.1, 78.0);
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
			s = "��";
		} else {
			s = "Ů";
		}
		System.out.println("������" + no.substring(6, 10) 
					+ "��" + no.substring(10, 12) + "��" + no.substring(12, 14) + "�ճ���,��" + s +"��");
	}
	
	public void eating() {
		System.out.println(name + "�ڳԷ�.");
	}
	public void sleeping() {
		System.out.println(name + "��˯��.");
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
			System.out.println("֤�����볤�Ȳ����Ϲ涨!");
			status = false;
		}
		int i;
		for (i = 0; i < no.length() - 1; ++i) {
			if (no.charAt(i) > '9' || no.charAt(i) < '0') {
				System.out.println("֤�������а����Ƿ��ַ�, �����밢��������!");
				status = false;
			}
		}
		
		if ((no.charAt(16) % 2) == 1 ) {
			if (!sex.equals("��")) {
				System.out.println("֤�������Ա��������Ա�ͬ!");
				status = false;
			}
		} else {
			if (!sex.equals("Ů")) {
				System.out.println("֤�������Ա��������Ա�ͬ!");
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
