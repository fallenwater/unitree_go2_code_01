from setuptools import setup
from glob import glob

package_name = 'go2_tutorial_py'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + "/launch", glob("launch/*.launch.py")),
        ('share/' + package_name + "/params", glob("params/*.yaml")),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='xn',
    maintainer_email='xn@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'go2_ctrl = go2_tutorial_py.go2_ctrl:main',
            'go2_state = go2_tutorial_py.go2_state:main',
            'go2_cruising_service = go2_tutorial_py.go2_cruising_service:main',
            'go2_cruising_client = go2_tutorial_py.go2_cruising_client:main',
        ],
    },
)
