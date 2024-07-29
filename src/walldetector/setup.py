from setuptools import find_packages, setup

package_name = 'walldetector'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='sami',
    maintainer_email='samitrad7@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'finder=walldetector.finder:main',
            'follower=walldetector.follower:main',
            'laptime_server=walldetector.laptime_server:main',
            'laptime_client=walldetector.laptime_client:main'
        ],
    },
)
