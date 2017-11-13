before_commit: format check_lines

check_lines:
	@for file in $$(find . -name *.cpp); do if [ `cat $$file | wc -l` -gt 200 ]; then echo "$$file have more than 200 lines"; fi; done;

format:
	@astyle --options=astyle.cfg -R "src/*" | grep -v Unchanged
	@astyle --options=astyle.cfg -R "test/*.cpp" | grep -v Unchanged

